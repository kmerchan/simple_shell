#include "header.h"

/**
 * main - reads, tokenizes, and executes commands and arguments, like shell
 * Return: 0 if successful
 */

int main(void)
{
	char *prompt = "$ ";
	char *buffer;
	char *path;
	ssize_t BUFF_SIZE = 1024;
	ssize_t rd = 0, w = 0;
	const char *space = " ";
	char **args;
	int i = 0, path_check = 0;
	struct stat buf;

	while (1)
	{
		/* dynamically allocate memory for buffer */
		buffer = malloc(sizeof(char) * BUFF_SIZE);
		if (buffer == NULL)
			malloc_error();
/*		printf("We have malloced our buffer\n");
 */
		/* writes prompt to stdout if command not piped in */
		if (isatty(STDIN))
		{
			w = write(STDOUT, prompt, _strlen(prompt));
			if (w < 0)
			{
				free(buffer);
				write_error();
			}
		}

		/* read to buffer using getline function */
		rd = _getline(&buffer, &BUFF_SIZE, stdin);
		if (rd < 0)
		{
			free(buffer);
			getline_error();
		}
/*		printf("We have read %ld bytes. Here's what we read:\n", rd);
		printf("%s", buffer);
*/
		/* parses the function based on delim, create args like argv */
		args = _parse(buffer, space);
/*		printf("Here's how Shelly sets args\n");
		for (i = 0; args[i]; i++)
			printf("%s\n", args[i]);
*/
		free(buffer);
		if (_strcmp(args[0], "exit") && _strcmp(args[0], "env"))
		{
			if (stat(args[0], &buf))
			{
				path_check = 1;
				path = checkpath(findpath(), args[0]);
			}
			else
				path = args[0];
/*			printf("Here's how Shelly sets path\n");
			printf("%s\n", path);
*/
			/* fork into child processes to execute program */
			execute(path, args);
/*			printf("We finished executing program %s\n", path);
 */
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			printenv();
/*			printf("We finished printing env\n");
 */		}
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args[i]);
		free(args);
		if (path_check)
			free(path);
		path_check = 0;
/*		printf("Now everything should be free!\n");
 */
	}
	return (0);
}
