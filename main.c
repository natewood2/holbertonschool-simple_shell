#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int main(int ac, char **av) {
    char *buffer = NULL;
    size_t bufferSize = 0;
    int value = 0;
    char *path = NULL;
    char **env;
    int i;
    char *new_buffer = NULL;
    char *slash = "/";

    for (env = environ; *env != NULL; env++) 
	{
        if (strncmp(*env, "PATH=", 5) == 0) 
		{
            path = *env + 5;
            break;
        }
    }
    printf("Path: %s\n", path);

    while (1) 
	{
        printf("$ ");
        value = getline(&buffer, &bufferSize, stdin);
        if (value == -1) 
		{
            printf("error\n");
            continue;
        }
        if (strcmp(buffer, "exit\n") == 0) 
		{
            break;
        }

        for (i = 1; i < ac; i++) 
		{
            printf("%s\n", av[i]);
        }

        if (path != NULL) {
            int needSlash = (path[0] != '/');
            new_buffer = (char *)malloc(strlen(path) + needSlash + 1); // +1 for null terminator
            if (new_buffer != NULL) 
			{
                if (needSlash) 
				{
                    strcpy(new_buffer, slash);
                } 
				else 
				{
                    new_buffer[0] = '\0'; // Initialize to an empty string
                }
                strcat(new_buffer, path);
                printf("new_buffer: %s\n", new_buffer);
                free(new_buffer);
            }
        }
        free(buffer);
        buffer = NULL; // Reset buffer to NULL for the next getline call
    }

    return 0;
}
