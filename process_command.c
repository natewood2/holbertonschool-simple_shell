#include "main.h"

void process_command(char *buffer) 
{
    char *args[10];
    int maxArgs = 10;
    char *fullPath;

    tokenize_input(buffer, args, maxArgs);

    if (is_absolute_or_relative_path(args[0])) 
    {
        if (can_execute_command(args[0])) 
        {
            fullPath = strdup(args[0]);
        } 
        else 
        {
            fprintf(stderr, "Command not executable: %s\n", args[0]);
            return;
        }
    } 
    else 
    {
        fullPath = find_command_in_path(args[0]);
        if (fullPath == NULL) 
        {
            fprintf(stderr, "Command not found: %s\n", args[0]);
            return;
        }
    }

    execute_command(fullPath, args);
    free(fullPath);
}
