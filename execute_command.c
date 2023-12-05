#include "main.h"

void execute_command(char *fullPath, char **args) {
    pid_t pid;
    int status;
    int exit_status;

    pid = fork();
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
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) 
        {
            exit_status = WEXITSTATUS(status);
            exit(exit_status);
        }
    } 
    else 
    {
        fprintf(stderr, "Failed to fork\n");
        exit(EXIT_FAILURE);
    }
}
