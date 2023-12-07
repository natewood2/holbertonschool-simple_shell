#include "main.h"
/**
 * is_full_path - Checks if a command is a full path or not
 * @cmd: The command to check
 * Return: 1 if command is full path, otherwise 0
 */
int is_full_path(const char *cmd)
{
	/* checks if '/' is present in cmd */
	return (strchr(cmd, '/') != NULL);
}
