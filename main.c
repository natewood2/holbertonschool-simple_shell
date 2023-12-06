#include "main.h"
#include "command.h"

int main(void)
{
	char *buffer = NULL;
	size_t bufferSize = 0;
	ssize_t value;
	char *args[20];
	int commandFound;
	int i;
	char *token;
	char *path = NULL;

	while (1)
	{
		path = get_environ(environ);

		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		value = getline(&buffer, &bufferSize, stdin);
		if (value == -1)
		{
			if (buffer)
			{
			free(buffer);
			}
			if (path)
			{
				free(path);
			}
			exit(EXIT_SUCCESS);
		}

		buffer[value - 1] = '\0';
		if (strcmp(buffer, "exit") == 0)
		{
			if (path)
			{
				free(path);
			}
			break;
		}

		i = 0;
		token = strtok(buffer, " \n\t");
		while (token != NULL && i < 20)
		{
			args[i++] = token;
			token = strtok(NULL, " \n\t");
		}
		args[i] = NULL;

		if (args[0] != NULL)
		{
			if (strchr(args[0], '/'))
			{
				execute_command(args[0], args);
			}
			else
			{
				commandFound = check_path_and_execute(args[0], args);
				if (!commandFound)
				{
					printf("%s: Command not found\n", args[0]);
				}
			}
		}

		if (buffer)
		{
			free(buffer);
		}
		buffer = NULL;
		bufferSize = 0;
		if (path)
		{
			free(path);
			path = NULL;
		}
	}
	return (0);
}
