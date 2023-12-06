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
    int commandFound;
    int i;
    char *token;
    char *path;

    while (1) 
    {
        path = get_environ(environ);

        if (isatty(STDIN_FILENO)) 
        {
            write(STDOUT_FILENO, "$ ", 2);
        }

        value = getline(&buffer, &bufferSize, stdin);
        if (value == -1) 
        {
            printf("\n");
            free(path);
            break;
        }

        buffer[value - 1] = '\0';
        if (strcmp(buffer, "exit") == 0) 
        {
            free(path);
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
            if (strchr(args[0], '/')) {
                execute_command(args[0], args);
            } 
            else 
            {
                commandFound = check_path_and_execute(args[0], args);
                if (!commandFound) 
                {
                    printf("%s: Command not found\n", args[0]);
                }
            }
        }

        free(buffer);
        buffer = NULL;
        bufferSize = 0;
    }

    return 0;
}
