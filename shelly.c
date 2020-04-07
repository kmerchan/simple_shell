#include "header.h"

/**
 * main - reads, tokenizes, and executes commands and arguments, like shell
 * Return: 0 if successful
 */

int main(void)
{
	char *prompt = "$ ";
	char *buffer;
	size_t BUFF_SIZE = 4;
	ssize_t rd = 0;
	const char *space = " ";
	char **args;
	int check = 0;
	int i = 0;

	while (check != 3)
	{
		/* dynamically allocate memory for buffer */
		buffer = malloc(sizeof(char) * BUFF_SIZE);
		if (buffer == NULL)
			malloc_error();
/*		printf("We have malloced our buffer\n");
 */
		/* writes prompt to stdout */
		write(STDOUT_FILENO, prompt, 2);

		/* read to buffer using getline function */
		rd = _getline(&buffer, &BUFF_SIZE, stdin);
		if (rd < 0)
		{
			free(buffer);
			getline_error();
		}
		printf("We have read %zu bytes. Here's what we read:\n", rd);
		printf("%s", buffer);
		/* parses the function based on delim, create args like argv */
		args = _parse(buffer, space);
		free(buffer);
		printf("Here's how Shelly sets args\n");
		for (i = 0; args[i]; i++)
			printf("%s\n", args[i]);

		/* fork into parent and child processes to execute program */
		execute(args);
		printf("Awesome!  We finished executing program %s\n", args[0]);
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args[i]);
		free(args);
		printf("Now everything should be free.  Let's go again!\n");
		check++;
	}
	return (0);
}
