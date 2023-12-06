#include "main.h"

char *get_environ(char **env) 
{
    const char *pathPrefix = "PATH=";
    const size_t prefixLen = strlen(pathPrefix);
    char *path = NULL;

    while (*env != NULL) 
    {
        if (strncmp(*env, pathPrefix, prefixLen) == 0) 
        {
            path = strdup(*env + prefixLen);
            if (!path) 
            {
                perror("path");
                exit(EXIT_FAILURE);
            }
            break;
        }
        env++;
    }
    free(path);
    return path;
}
