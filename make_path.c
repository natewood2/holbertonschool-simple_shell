#include "main.h"

char *construct_full_path(const char *dir, const char *cmd) 
{
    char *full_path = malloc(strlen(dir) + strlen(cmd) + 2);
    if (full_path != NULL) 
    {
        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, cmd);
    }
    return (full_path);
}
