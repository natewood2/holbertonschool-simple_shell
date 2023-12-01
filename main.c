#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "command.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused))) 
{
    char *buffer = NULL;
    size_t bufferSize = 0;
    int value;
    char *fullPath;
    pid_t pid;     
    char *args[10];
    int argCount; 
    char *token;

    while (1) 
    {
        printf("$ ");
        value = getline(&buffer, &bufferSize, stdin);
        if (value == -1) 
        {
            perror("getline failed");
            free(buffer);
            exit(EXIT_FAILURE);
        }
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "exit") == 0) 
        {
            break;
        }

       
        argCount = 0;
        token = strtok(buffer, " ");
        while (token != NULL && argCount < 10) 
        {
            args[argCount++] = token;
            token = strtok(NULL, " ");
        }
        args[argCount] = NULL;

       
        fullPath = find_command_in_path(args[0]);
        if (fullPath == NULL) 
        {
            fprintf(stderr, "Command not found: %s\n", args[0]);
            continue;
        }

        
        pid = fork();
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

        free(fullPath);
    }

    free(buffer);
    return 0;
}
