#include "main.h"
/**
 * check_path_and_execute - checking path and execution
 * @cmd: command
 * @args: arguments
 * Return: (1)
*/
int check_path_and_execute(const char *cmd, char **args)
{
	char *path = get_environ(environ);
	char *dir;
	char commandPath[1024];

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		sprintf(commandPath, "%s/%s", dir, cmd);
		if (access(commandPath, X_OK) == 0)
		{
			execute_command(commandPath, args);
			free(path);
			return (1);
		}
		dir = strtok(NULL, ":");
	}
free(path);
return (0);
}
