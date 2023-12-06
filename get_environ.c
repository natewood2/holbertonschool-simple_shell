#include "main.h"
/**
 * get_environ - Get value of PATH environment vari
 * @env: Pointer to array of environment vari
 * Return: pointer to string of PATH or NULL
 */
char *get_environ(char **env)
{
	const char *pathPrefix = "PATH=";
	const size_t prefixLen = strlen(pathPrefix);
	char *path = NULL;

	/* Loop through the environment variables */
	while (*env != NULL)
	{
		/* Check if the current envir vari starts with "PATH=" */
		if (strncmp(*env, pathPrefix, prefixLen) == 0)
		{
			/* Allocate memory for PATH value and copy it */
			path = strdup(*env + prefixLen);

			/*checks if memory allocatioon failed */
			if (!path)
			{
			/* Print an error message and exit if allocation failes */
			perror("path");
			exit(EXIT_FAILURE);
			}

			/* If PATH is found, break out of loop */
			break;
		}
		env++;
	}
	return (path);
}
