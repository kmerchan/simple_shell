#include "header.h"

/**
 * main - reads, tokenizes, and executes commands and arguments, like shell
 * Return: 0 if successful
 */

int main(void)
{
	char *buffer, *path, *prompt = "$ ";
	ssize_t BUFF_SIZE = 1024, w = 0;
	const char *space = " ";
	char **args;
	int user_input = 0, check_path = 0, stat_check = 0;

	while (1)
	{
		if (isatty(STDIN))
		{
			user_input = 1;
			w = write(STDOUT, prompt, _strlen(prompt));
			if (w < 0)
				write_error();
		}
		buffer = malloc(sizeof(char) * BUFF_SIZE);
		if (buffer == NULL)
			malloc_error();
		_getline(&buffer, &BUFF_SIZE, stdin, user_input, stat_check);
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
			stat_check = 0;
			if (_strcmp(args[0], "\n") == 0)
				check_path = 0;
			else if (_strcmp(args[0], "env"))
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
