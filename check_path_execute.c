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

	/* Tokenize PATH to individual directories */
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		/* Construct full path for the command */
		sprintf(commandPath, "%s/%s", dir, cmd);

		/* Check if the command is executable in the directory */
		if (access(commandPath, X_OK) == 0)
		{
			execute_command(commandPath, args);
			free(path);
			return (1);
		}
		dir = strtok(NULL, ":"); /* Move to the next directory in PATH */
	}
free(path);
return (0); /* Command not found */
}
