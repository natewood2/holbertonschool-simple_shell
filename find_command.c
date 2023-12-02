#include "command.h"
/**
 * find_command_in_path - finding commands
 * @cmd: cmd
 * Return: NULL
*/
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
	}
	if (full_path)
	{
		snprintf(full_path, full_path_size, "%s/%s", token, cmd);
	}
	if (can_execute_command(full_path))
	{
		free(path);
		return (full_path);
	}
	free(full_path);
	token = strtok(NULL, ":");
	free(path);
	return (NULL);
}
