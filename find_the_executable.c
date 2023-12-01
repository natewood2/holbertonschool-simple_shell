#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "main.h"

/*int can_execute_command(const char *full_path, char *const argv[]) 
{
    pid_t pid;
    int status;
    int exit_status;

    // Check if the file exists and is executable
    if (access(full_path, F_OK) != -1 && access(full_path, X_OK) != -1) 
    {
        pid = fork();
        if (pid == -1) 
        {
            // Fork failed
            return 0;
        } 
        else if (pid == 0) 
        {
            // Child process
            execve(full_path, argv, environ);
            exit(126); // If execve returns, it failed
        } 
        else 
        {
            // Parent process
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) 
            {
                exit_status = WEXITSTATUS(status);
                return (exit_status == 0);
            }
        }
    }
    return 0; // File doesn't exist or isn't executable
}
*/
int can_execute_command(const char *full_path) 
{
    return access(full_path, F_OK) != -1 && access(full_path, X_OK) != -1;
}

char *find_command_in_path(const char *cmd) 
{
    char *path_env;
    char *path;
    char *token;
    char *full_path;
    size_t full_path_size;

    path_env = getenv("PATH");
    if (!path_env) 
    {
        return NULL;
    }

    path = strdup(path_env);
    if (!path) 
    {
        return NULL;
    }

    token = strtok(path, ":");
    while (token != NULL) 
    {
        full_path_size = strlen(token) + strlen(cmd) + 2; // +2 for '/' and '\0'
        full_path = malloc(full_path_size);
        if (full_path) 
        {
            snprintf(full_path, full_path_size, "%s/%s", token, cmd);
            if (can_execute_command(full_path)) 
            {
                free(path);
                return full_path; // Executable found
            }
            free(full_path);
        }
        token = strtok(NULL, ":");
    }

    free(path);
    return NULL; // Command not found
}
/*char *find_command_in_path(const char *cmd) 
{
    char *path_env;
    char *path;
    char *token;
    char *full_path;
    char *args[2]; // Dummy argument array for execve
    size_t full_path_size;

    path_env = getenv("PATH");
    if (!path_env) 
    {
        return NULL;
    }

    path = strdup(path_env);
    if (!path) 
    {
        return NULL;
    }

    token = strtok(path, ":");
    args[0] = NULL;
    args[1] = NULL;

    while (token != NULL) 
    {
        full_path_size = strlen(token) + strlen(cmd) + 2; // +2 for '/' and '\0'
        full_path = malloc(full_path_size);
        if (full_path) 
        {
            snprintf(full_path, full_path_size, "%s/%s", token, cmd);
            printf("Checking path: %s\n", full_path); // Debug print
            args[0] = full_path; // Set command to execute

            if (can_execute_command(full_path, args)) 
            {
                free(path);
                return full_path; // Executable found
            }
            free(full_path);
        }
        token = strtok(NULL, ":");
    }

    free(path);
    return NULL; // Command not found
}
*/
