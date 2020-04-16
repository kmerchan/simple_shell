#include "header.h"

/**
 * main - reads, tokenizes, and executes commands and arguments, like shell
 * Return: 0 if successful
 */

int main(void)
{
	char *buffer, *path, **args, *space = " ";
	ssize_t BUFF_SIZE = 1024;
	int user_input = 0, check_path = 0, sts = 0, lc = 1;


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
			find_and_run(&buffer, &args, &path, &sts, &check_path, lc);
			free_all_except_buffer(&path, &check_path, &args);
		}
		free(buffer);
		lc++;
	}
	return (sts);
}


/**
 * find_and_run - function to match command to builtin and run builtin program
 * or to check if command is an executable program and run that
 * @buffer: input pointer to buffer read to in _getline
 * @args: input 2D array of tokenized arguments
 * @path: input pointer to string to set path to before executing
 * @sts: input status of previously run command
 * @check_path: input pointer to variable to indicate if path is set in mem
 * @lc: input integer of line count
 */

void find_and_run(char **buffer, char ***args, char **path, int *sts,
		  int *check_path, int lc)
{
	int i = 0;
	get_program builtins[] = { {"exit", goodbye}, {"env", printenv},
				   {"\n", newline}, {NULL, NULL} };

	for (i = 0; builtins[i].name; i++)
	{
		if ((_strcmp((*args)[0], builtins[i].name)) == 0)
		{
			builtins[i].func(buffer, args, sts);
			break;
		}
		if (builtins[i + 1].name == NULL)
		{
			*check_path = 1;
			check_exec(path, args, buffer, sts, lc);
					if (*sts == 0)
						execute(path, args, buffer);
				}
			}
}
