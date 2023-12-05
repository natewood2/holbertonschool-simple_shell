#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "command.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused))) 
{
    char *buffer = NULL;
    size_t bufferSize = 0;
    ssize_t length;

    while (1) 
    {
        if (isatty(STDIN_FILENO)) 
        {
            printf("$ ");
        }
        length = getline(&buffer, &bufferSize, stdin);

        if (length == -1) 
        {
            printf("\n");
            break;
        }

        buffer[strcspn(buffer, "\n")] = 0;
        if (buffer[0] == '\0') 
        {
            continue;
        }

        if (strcmp(buffer, "exit") == 0) 
        {
            break;
        }

        process_command(buffer);

    }

    free(buffer);
    return (0);
}
