#include "header.h"

/**
 * main - reads, tokenizes, and executes commands and arguments, like shell
 * Return: 0 if successful
 */

int main(void)
{
	char *prompt = "$ ";
	char *buffer;
	size_t BUFF_SIZE = 1024;
	ssize_t rd = 0;
	const char *space = " ";
	char **args;
	int check = 0, i = 0;

	while (check == 0)
	{
		/* writes prompt to stdout */
		write(STDOUT_FILENO, prompt, 2);

		/* dynamically allocate memory for buffer */
		buffer = malloc(sizeof(char) * BUFF_SIZE);
		if (buffer == NULL)
			malloc_error();

		/* read to buffer using getline function */
		rd = getline(&buffer, &BUFF_SIZE, stdin);
		if (rd < 0)
		{
			free(buffer);
			getline_error();
		}

		/* parses the function based on delim, create args like argv */
		args = _parse(buffer, space);
		free(buffer);

		/* fork into parent and child processes to execute program */
		execute(args);
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args[i]);
		free(args);
	}
	return (0);
}
