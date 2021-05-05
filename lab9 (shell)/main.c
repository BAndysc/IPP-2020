#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <sys/fcntl.h>
#include <pwd.h>
#include "input.h"
#include "parser.h"
#include "builtins.h"

#define PROCESS_CHILD 0

pid_t safeFork(void)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "CRITICAL ERROR IN FORK\n");
        exit(1);
    }
    return pid;
}

void safePipe(int* readPipe, int* writePipe)
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        fprintf(stderr, "CRITICAL ERROR IN PIPE\n");
        exit(1);
    }
    *readPipe = fd[0];
    *writePipe = fd[1];
}

char* getUsername()
{
    struct passwd *p = getpwuid(getuid());
    return p->pw_name;
}

void execute(Tokenized* tokenized, size_t start, size_t end)
{
    assert(end >= start);
    size_t count = (end - start + 1);

    char** arguments = malloc(sizeof(char*) * (count + 1));

    for (int i = 0; i < count; ++i)
        arguments[i] = stringRaw(tokenized->tokens[i + start]);

    arguments[count] = NULL;

    int retCode = execvp(arguments[0], arguments);
    assert(retCode == -1);

    if (errno == ENOENT)
    {
        printf("File not found %s\n", arguments[0]);
        exit(1);
    }
}

String* getNextLine(bool doPrint, int lastExitCode)
{
    char* pwd = getcwd(NULL, 0);
    if (doPrint)
       printf("\e[44m\e[44;37m%s\e[0m:%s (%d)$ ", getUsername(), pwd, lastExitCode);
    free(pwd);
    return readLine();
}

bool isComment(String* line)
{
    return charAt(line, 0) == '#';
}

void redirectStdin(char const* file)
{
    int input = open(file, O_RDONLY);
    dup2(input, STDIN_FILENO);
    close(input);
}

int main(int argc, char** argv) {
    String* line;
    int lastExitCode = 0;
    bool doPrintPrompt = true;

    if (argc == 2)
    {
        doPrintPrompt = false;
        redirectStdin(argv[1]);
    }

    initBuiltins();

    while ((line = getNextLine(doPrintPrompt, lastExitCode)))
    {
        if (isComment(line))
            goto ignoreLine;

        lastExitCode = 0;
        Tokenized tokenized = Tokenize(line);

        if (tokenized.size == 0)
            goto ignoreTokens;

        ExecBuiltinResult builtinResult = tryExecuteBuiltin(&tokenized);
        if (builtinResult == BUILTIN_OK)
            goto ignoreTokens;

        if (builtinResult == BUILTIN_EXIT)
        {
            freeTokenized(tokenized);
            freeString(line);
            return 0;
        }

        String* redirectStdout = NULL;
        String* piped = NULL;
        size_t effectiveArguments = tokenized.size;
        if (tokenized.size >= 2 && stringEquals(tokenized.tokens[tokenized.size - 2], ">"))
        {
            effectiveArguments -= 2;
            redirectStdout = tokenized.tokens[tokenized.size - 1];
        }
        if (tokenized.size >= 2 && stringEquals(tokenized.tokens[tokenized.size - 2], "|"))
        {
            effectiveArguments -= 2;
            piped = tokenized.tokens[tokenized.size - 1];
        }

        if (safeFork() == PROCESS_CHILD)
        {
            if (redirectStdout)
            {
                int fd = open(stringRaw(redirectStdout), O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }
            if (piped)
            {
                int readPipe, writePipe;
                safePipe(&readPipe, &writePipe);

                if (safeFork() == PROCESS_CHILD)
                {
                    dup2(readPipe, STDIN_FILENO);
                    close(readPipe);
                    close(writePipe);

                    execute(&tokenized, effectiveArguments + 1, tokenized.size - 1);
                }
                else
                {
                    dup2(writePipe, STDOUT_FILENO);
                    close(readPipe);
                    close(writePipe);
                }
            }
            execute(&tokenized, 0, effectiveArguments - 1);
        }
        else
        {
            int lastExitStatus;
            wait(&lastExitStatus);
            lastExitCode = WEXITSTATUS(lastExitStatus);
        }

ignoreTokens:
        freeTokenized(tokenized);

ignoreLine:
        freeString(line);
    }
    return 0;
}
