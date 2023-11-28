
#include "main.h"

char *_strtok(char *str, const char *delim)
{
	char *token = strtok(str, " ");

	while (token != NULL)
	{
		
	}
}
int main(int ac __attribute__((unused)), char **av)
{
	char *buffer = NULL;
	size_t *bufferSize = 0;

	bufferSize = malloc(sizeof(int));

	if (bufferSize == NULL) 
		free(bufferSize);

	while (1)
	{
		printf("$ ");
		getline(&buffer, bufferSize, stdin);
		while (*av != NULL)
    	{
			printf("Argue away:%s\n", *av);
			av++;
    	}
	}
    // Return 0 to indicate successful execution
    return (0);
}
