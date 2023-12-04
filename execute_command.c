#include "main.h"

void execute_command(char *fullPath, char **args) 
{
    pid_t pid = fork();
    if (pid == 0) 
    {
        execve(fullPath, args, environ);
        fprintf(stderr, "Failed to execute '%s'\n", fullPath);
        exit(EXIT_FAILURE);
    } 
    else if (pid > 0) 
    {
        wait(NULL);
    } 
    else 
    {
        fprintf(stderr, "Failed to fork\n");
    }
}
