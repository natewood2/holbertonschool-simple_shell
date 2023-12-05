#include "command.h"
/**
 * find_command_in_path - finding commands
 * @cmd: cmd
 * Return: NULL
*/
char *find_command_in_path(const char *cmd) 
{
    char *path_env, *path, *token, *full_path;
    size_t full_path_size;

    path_env = getenv("PATH");
    if (!path_env) 
    {
        return (NULL);
    }

    path = strdup(path_env);
    if (!path) 
    {
        return (NULL);
    }

    token = strtok(path, ":");
    while (token != NULL) 
    {
        full_path_size = strlen(token) + strlen(cmd) + 2;
        full_path = malloc(full_path_size);

        if (full_path) 
        {
            sprintf(full_path, "%s/%s", token, cmd);
            if (access(full_path, X_OK) != -1) 
            {
                free(path);
                return (full_path);
            }
            free(full_path);
        }
        token = strtok(NULL, ":");
    }

    free(path);
    return (NULL);
}
