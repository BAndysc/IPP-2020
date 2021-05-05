#ifndef IPPSHELLTEST_BUILTINS_H
#define IPPSHELLTEST_BUILTINS_H

#include <stdbool.h>
#include "parser.h"

void initBuiltins();

typedef enum ExecBuiltinResult
{
    BUILTIN_OK,
    NO_BUILTIN,
    BUILTIN_EXIT
} ExecBuiltinResult;

ExecBuiltinResult tryExecuteBuiltin(Tokenized* tokens);

#endif //IPPSHELLTEST_BUILTINS_H
