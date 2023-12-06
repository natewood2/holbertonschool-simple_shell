#include "main.h"
/**
 * construct_full_path - Construct full path from dir and cmd
 * @dir: Directory path
 * @cmd: Command name
 * Return: Pointer to string containing full path or NULL on failure
 */
char *construct_full_path(const char *dir, const char *cmd)
{
	char *full_path = malloc(strlen(dir) + strlen(cmd) + 2);

	/* Check if memory allocation was successful */
	if (full_path != NULL)
	{
		/* Copy directory path into full_path */
		strcpy(full_path, dir);

		/* Concatenate '/' to separate dir and cmd */
		strcat(full_path, "/");

		/* Concatenate command name to complete the full path */
		strcat(full_path, cmd);
	}
	return (full_path);
}
