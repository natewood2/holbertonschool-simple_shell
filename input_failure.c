#include "main.h"

int check_input_failure(ssize_t length, char *buffer) 
{
    if (length == -1) 
    {
        printf("\n");
        free(buffer);
        return 1;
    }
    return 0;
}
