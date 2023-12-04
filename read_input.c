#include "main.h"

ssize_t read_input_line(char **buffer, size_t *bufferSize) 
{
    ssize_t length;
    printf("$ "); 
    if ((length = getline(buffer, bufferSize, stdin)) != -1) 
    {
        (*buffer)[strcspn(*buffer, "\n")] = 0;
    }
    return length;
}
