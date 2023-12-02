#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "command.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *buffer = NULL;
	size_t bufferSize = 0;
	int value;
	char *fullPath;
	pid_t pid;
	char *args[10];
	int argCount;
	char *token;

	/* Infinite loop for the shell prompt */
	while (1)
	{
		printf("$ "); /* Display the shell prompt */
		value = getline(&buffer, &bufferSize, stdin);

		/* Check if getline failed */
		if (value == -1)
		{
			printf("\n");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		buffer[strcspn(buffer, "\n")] = 0;

		/* Check for 'exit' command */
		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}

		/* Tokenize the input into arguments */
		argCount = 0;
		token = strtok(buffer, " ");
		while (token != NULL && argCount < 10)
		{
			args[argCount++] = token;
			token = strtok(NULL, " ");
		}
		args[argCount] = NULL;

		/* Find the full path of the command */
		fullPath = find_command_in_path(args[0]);
		if (fullPath == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			continue;
		}

		/* Fork the process */
		pid = fork();
		if (pid == 0) /* Child process */
		{
			execve(fullPath, args, environ);
			fprintf(stderr, "Failed to execute '%s'\n", fullPath);
			exit(EXIT_FAILURE);
		}
		/* Parent process */
		else if (pid > 0)
		{
			wait(NULL); /* Wait for child to be finished */
		}
		else /* Fork failed */
		{
			fprintf(stderr, "Failed to fork\n");
		}
		free(fullPath);
	}
	free(buffer);
	return (0); /* Return success */
}
