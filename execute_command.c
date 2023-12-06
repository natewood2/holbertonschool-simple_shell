#include "main.h"

int execute_command(char *command, char **args) 
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == 0) 
    {
        execve(command, args, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    } 
    else if (pid > 0) 
    {
        waitpid(pid, &status, 0);
    } 
    else 
    {
        perror("fork");
    }
    return (status);
}
