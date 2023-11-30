#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused))) 
{
    char *buffer = NULL;
    size_t bufferSize = 0;
    int value;
    char *fullPath;
    pid_t pid;      // Parent
    char *args[10]; // Array to hold command and arguments
    int argCount;   // Count of arguments
    char *token;    // For tokenizing the input

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
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        if (strcmp(buffer, "exit") == 0) 
        {
            break;
        }

        // Tokenize the input
        argCount = 0;
        token = strtok(buffer, " ");
        while (token != NULL && argCount < 10) 
        {
            args[argCount++] = token;
            token = strtok(NULL, " ");
        }
        args[argCount] = NULL;

        // Find the full path of the command
        fullPath = find_command_in_path(args[0]);
        if (fullPath == NULL) 
        {
            fprintf(stderr, "Command not found: %s\n", args[0]);
            continue;
        }

        // Fork and execute the command using execve
        pid = fork();
        if (pid == 0) 
        {
            // Child process
            execve(fullPath, args, environ);
            fprintf(stderr, "Failed to execute '%s'\n", fullPath);
            exit(EXIT_FAILURE);  // Ensure child process exits after execve failure
        } 
        else if (pid > 0) 
        {
            // Parent process
            wait(NULL);  // Wait for child process to finish
        } 
        else 
        {
            // Fork failed
            fprintf(stderr, "Failed to fork\n");
        }

        free(fullPath);
    }

    free(buffer);
    return 0;
}
