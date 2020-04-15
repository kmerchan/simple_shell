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
	int user_input = 0, check_path = 0, stat_check = 0;

	while (1)
	{
		buffer = malloc(sizeof(char) * BUFF_SIZE);
		if (buffer == NULL)
			malloc_error();
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
		rd = _getline(&buffer, &BUFF_SIZE, stdin, user_input, stat_check);
		if (rd < 0)
		{
			free(buffer);
			getline_error();
		}
		stat_check = 0;
		while (buffer != NULL)
		{
			args = _parse(buffer, space);
			if (args == NULL)
			{
				free(buffer);
				malloc_error();
			}
			if (args[0] == NULL)
			{
				free_args(&args);
				free(buffer);
				break;
			}
			buffer = reset(&buffer, &args, space);
			if (_strcmp(args[0], "exit") == 0)
				goodbye(&buffer, &args);
			if (_strcmp(args[0], "env"))
			{
				check_path = 1;
				stat_check = check_execute(&path, &args, &buffer);
				if (stat_check == 0)
					execute(&path, &args, &buffer);
			}
			else if (_strcmp(args[0], "env") == 0)
				printenv();
			if (check_path == 1)
				free(path);
			free_args(&args);
		}
		free(buffer);
	}
	return (0);
}
