#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtins.h"

#define BUILTIN_COMMAND_CD 0
#define BUILTIN_COMMAND_EXIT 1
#define BUILTIN_COMMAND_MAX 2

typedef ExecBuiltinResult (*builtinCommandHandler)(Tokenized* tokens);

typedef struct BuiltinCommand
{
    char const* command;
    int args;
    char const* help;
    builtinCommandHandler handler;
} BuiltinCommand;

static BuiltinCommand builtins[BUILTIN_COMMAND_MAX];

static ExecBuiltinResult handleCd(Tokenized* tokens)
{
    chdir(stringRaw(tokens->tokens[1]));
    return BUILTIN_OK;
}

static ExecBuiltinResult handleExit(Tokenized* tokens)
{
    return BUILTIN_EXIT;
}

void initBuiltins()
{
    builtins[BUILTIN_COMMAND_CD] = (BuiltinCommand){.command = "cd", .help = "cd [directory]", .args = 1, .handler = handleCd};
    builtins[BUILTIN_COMMAND_EXIT] = (BuiltinCommand){.command = "exit", .help = "exit", .args = 0, .handler = handleExit};
}

ExecBuiltinResult tryExecuteBuiltin(Tokenized* tokens)
{
    for (int i = 0; i < BUILTIN_COMMAND_MAX; ++i)
    {
        BuiltinCommand* builtin = builtins + i;
        if (stringEquals(tokens->tokens[0], builtin->command))
        {
            if (tokens->size - 1 != builtin->args)
            {
                printf("Usage: %s\n", builtin->help);
                return BUILTIN_OK;
            }

            return builtin->handler(tokens);
        }
    }

    return NO_BUILTIN;
}