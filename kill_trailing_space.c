#include "main.h"

void trim_trailing_spaces(char *str) 
{
    int end = strlen(str) - 1;
    while (end >= 0 && str[end] == ' ') 
    {
        end--;
    }
    str[end + 1] = '\0';
}
