#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "command.h"

int main(void) 
{
    const int MAX_PATH_LENGTH = 1024;
    char *buffer = NULL;
    size_t bufferSize = 0;
    ssize_t value;
    char **args;
    char *commandPath;
    int i;

    while (1) 
    {
        printf("$ ");
        fflush(stdout);

        value = getline(&buffer, &bufferSize, stdin);

        if (value == -1) 
        {
            if (bufferSize == 0 || buffer[0] == '\0') 
            {
                printf("\n");
                break;
            } 
            else 
            {
                free(buffer);
                buffer = NULL;
                bufferSize = 0;
                continue;
            }
        }

        buffer[value - 1] = '\0';

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        args = malloc(sizeof(char *) * (MAX_PATH_LENGTH / 2));
        if (!args) 
        {
            perror("malloc");
            continue;
        }

        args[0] = strtok(buffer, " ");
        for (i = 1; i < MAX_PATH_LENGTH / 2 && args[i - 1] != NULL; i++) 
        {
            args[i] = strtok(NULL, " ");
        }

        if (args[0] != NULL) 
        {
            if (is_full_path(args[0])) 
            {
                commandPath = strdup(args[0]);
            } 
            else 
            {
                commandPath = find_command_in_path(args[0]);
            }

            if (commandPath) 
            {
                execute_command(commandPath, args);
                free(commandPath);
            } 
            else 
            {
                printf("%s: Command not found\n", args[0]);
            }
        }

        free(args);
    }

    free(buffer);
    return 0;
}
