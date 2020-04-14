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
	int user_input = 0, i = 0, check_path = 0;

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
			user_input = 1;
			w = write(STDOUT, prompt, _strlen(prompt));
			if (w < 0)
			{
				free(buffer);
				write_error();
			}
		}

		/* read to buffer using getline function */
		rd = _getline(&buffer, &BUFF_SIZE, stdin, user_input);
		if (rd < 0)
		{
			free(buffer);
			getline_error();
		}
/*		printf("We have read %ld bytes. Here's what we read:\n", rd);
		printf("%s", buffer);
*/
		while (buffer != NULL)
		{
			/* parses the function based on delim, create args like argv */
			args = _parse(buffer, space);
			if (args == NULL)
			{
				free(buffer);
				malloc_error();
			}
			if (args[0] == NULL)
			{
				free_args(args)
				free(buffer);
				break;
			}
/*			printf("Here's how Shelly sets args\n");
			for (i = 0; args[i]; i++)
				printf("%s!\n", args[i]);
*/
			buffer = reset(&buffer, &args, space);
/*			printf("This is reset buffer: %s\n", buffer);
 */
			if (_strcmp(args[0], "exit") == 0)
				goodbye(&buffer, &args);
			if (_strcmp(args[0], "env"))
			{
				check_path = 1;
				check_execute(&path, &args, &buffer);
			/* Fork into child processes to execute program */
				execute(&path, &args, &buffer);
/*				printf("We finished executing program %s\n", path);
 */
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				printenv();
/*				printf("We finished printing env\n");
 */
			}
			if (check_path == 1)
				free(path);
			free_args(&args);
/*			printf("Now everything, except buffer should be free!\n");
 */
		}
		free(buffer);
	}
	return (0);
}
