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
        length = read_input_line(&buffer, &bufferSize);

        if (check_input_failure(length, buffer)) 
        {
            exit(EXIT_FAILURE);
        }

        if (strcmp(buffer, "exit") == 0) 
        {
            break;
        }

        process_command(buffer);
    }

    free(buffer);
    return 0;
}
