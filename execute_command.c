#include "main.h"

void execute_command(char *fullPath, char **args) 
{
    pid_t pid = fork();
    if (pid == 0) 
    {
        if (execve(fullPath, args, environ) == -1) 
        {
            fprintf(stderr, "Failed to execute '%s'\n", fullPath);
            exit(EXIT_FAILURE);
        }
    } 
    else if (pid > 0) 
    {
        int status;
        waitpid(pid, &status, 0);
    } 
    else 
    {
        fprintf(stderr, "Failed to fork\n");
    }
}
