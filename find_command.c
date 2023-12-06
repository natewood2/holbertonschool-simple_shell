#include "command.h"
#include "main.h"
/**
 * find_command_in_path - finding commands
 * @cmd: cmd
 * Return: NULL
*/
char *find_command_in_path(const char *cmd)
{
	const int MAX_PATH_LENGTH = 1024;
	char *path = NULL;
	char *token;
	char *full_path;
	int i;

	full_path = malloc(MAX_PATH_LENGTH);
	if (!full_path)
	{
		return (NULL);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}

	if (!path)
	{
		free(full_path);
		return (NULL);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, cmd);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		token = strtok(NULL, ":");
	}
	free(full_path);
	return (NULL);
}
