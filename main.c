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
    ssize_t length;

    while (1) 
    {
        printf("$ ");
        length = getline(&buffer, &bufferSize, stdin);

        if (length == 1 && buffer[0] == '\n') 
        {
            continue;
        }

        if (length == -1) 
        {
            printf("\n");
            break;
        }

        if (length > 0 && buffer[length - 1] == '\n') 
        {
            buffer[length - 1] = '\0';
        }

        process_command(buffer);
    }

    free(buffer);
    return 0;
}
