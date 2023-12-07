#include "main.h"
/**
 * execute_command - execution function
 * @command: commands
 * @args: args
 * Return: return (status)
*/
int execute_command(char *command, char **args)
{
	pid_t pid;
	int status = 0;

	/* Create a child process */
	pid = fork();
	if (pid == 0) /* Child process */
	{
		/* Execute the command with given arguments */
		execve(command, args, NULL);
		perror("execve");
		exit(EXIT_FAILURE); 
	}
	else if (pid > 0) /* Parent process */
	{
		/* Wait for the child process to complete */
		waitpid(pid, &status, 0);
	}
	else /* fork */
	{
		perror("fork"); /* Print error if fork fails */
	}
return (status); /* Return the status of the command execution */
}
