#include "main.h"

int tokenize_input(char *buffer, char **args, int max_args) 
{
    char *token;
    int argCount = 0;

    token = strtok(buffer, " ");
    while (token != NULL && argCount < max_args) 
    {
        args[argCount++] = token;
        token = strtok(NULL, " ");
    }
    args[argCount] = NULL;
    return (argCount);
}
