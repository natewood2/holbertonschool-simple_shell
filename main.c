#include "main.h"
#include "command.h"
/**
 * main - Entry point of Shell program
 *
 * Return: returns 0 upon successful completion
 */
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

	/* Shell execution loop */
	while (1)
	{
		/* Retrieve the PATH from the environment */
		path = get_environ(environ);

		/* Print prompt if the input is from a terminal */
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		/* Read input from the user */
		value = getline(&buffer, &bufferSize, stdin);
		if (value == -1)
		{
			/* Handle EOF or error in input */
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

		/* Process the input */
		buffer[value - 1] = '\0';
		if (strcmp(buffer, "exit") == 0)
		{
			if (path)
			{
				free(path);
			}
			break;
		}

		/* Tokenize the input into arguments */
		i = 0;
		token = strtok(buffer, " \n\t");
		while (token != NULL && i < 20)
		{
			args[i++] = token;
			token = strtok(NULL, " \n\t");
		}
		args[i] = NULL;

		/* Execute the command */
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

		/* Clean up memory and reset variables */
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
