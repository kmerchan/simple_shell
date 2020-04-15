#include "header.h"

/**
 * main - reads, tokenizes, and executes commands and arguments, like shell
 * Return: 0 if successful
 */

int main(void)
{
	char *buffer, *path, **args, *space = " ";
	ssize_t BUFF_SIZE = 1024;
	int i = 0, user_input = 0, check_path = 0, sts = 0, lc = 1;
	get_program builtins[] = { {"exit", goodbye}, {"env", printenv},
				   {"\n", newline}, {NULL, NULL} };

	while (1)
	{
		if (isatty(STDIN))
			user_input = print_prompt();
		buffer = malloc(sizeof(char) * BUFF_SIZE);
		if (buffer == NULL)
			malloc_error();
		_getline(&buffer, &BUFF_SIZE, stdin, user_input, sts);
		while (buffer != NULL)
		{
			args = _parse(buffer, space);
			if (args == NULL)
				malloc_error();
			buffer = reset(&buffer, &args, space);
			for (i = 0; builtins[i].name; i++)
			{
				if ((_strcmp(args[0], builtins[i].name)) == 0)
				{
					builtins[i].func(&buffer, &args, &sts);
					break;
				}
				if (builtins[i + 1].name == NULL)
				{
					check_path = 1;
					check_exec(&path, &args, &buffer, &sts, lc);
					if (sts == 0)
						execute(&path, &args, &buffer);
				}
			}
			free_all_except_buffer(&path, &check_path, &args);
		}
		free(buffer);
		lc++;
	}
	return (0);
}
