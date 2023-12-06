#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "command.h"

int main(void) 
{
    char *buffer = NULL;
    size_t bufferSize = 0;
    ssize_t value;
    char *args[20];
    char *commandPath;
    char *token;
    int i;

    while (1) 
    {
        printf("$ ");
        fflush(stdout);

        value = getline(&buffer, &bufferSize, stdin);

        if (value == -1) 
        {
            printf("\n");
            break;
        }

        buffer[value - 1] = '\0';

        if (strcmp(buffer, "exit") == 0) 
        {
            break;
        }

        i = 0;
        token = strtok(buffer, " \n\t");
        while (token != NULL && i < 20) 
        {
            args[i++] = token;
            token = strtok(NULL, " \n\t");
        }
        args[i] = NULL;

        if (args[0] != NULL) 
        {
            if (strchr(args[0], '/')) 
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

        free(buffer);
        buffer = NULL;
        bufferSize = 0;
    }

    return 0;
}
