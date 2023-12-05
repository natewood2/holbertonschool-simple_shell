#include "main.h"

void process_command(char *buffer) 
{
    char *args[MAX_ARGS];
    char *token;
    int argCount = 0;

    token = strtok(buffer, " ");
    while (token != NULL && argCount < MAX_ARGS) 
    {
        args[argCount++] = token;
        token = strtok(NULL, " ");
    }
    args[argCount] = NULL;

    if (args[0] != NULL) 
    {
        if (strcmp(args[0], "exit") == 0) 
        {
            exit(0);
        }
        execute_command(args[0], args);
    }
}
