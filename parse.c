#include "header.h"

#define NOT_DELIM (buffer[j] != delim[0] && buffer[j])

/**
 * _parse - function to tokenize arguments and set in 2D array similar to argv
 * @buffer: input string to tokenize/separate into arguments
 *
 * @delim: input deliminator to tokenize buffer at specific breakpoints
 *
 * Return: double pointer to 2D argument array args
 */

char **_parse(char *buffer, const char *delim)
{
	char **args;
	ssize_t i = 0, j = 0, k = 0, j_store = 0, arg_size = 0, arg_count = 1;

	arg_count = arg_counting(buffer, delim);
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (args == NULL)
	{
		free(buffer);
		malloc_error();
	}
	for (i = 0; i < arg_count; i++)
	{
		for (j_store = j, arg_size = 0; NOT_DELIM; j++)
			arg_size++;
		if (i == (arg_count - 1))
			arg_size--;
		args[i] = malloc(sizeof(char) * (arg_size + 1));
		if (args[i] == NULL)
		{
			if (i != 0)
			{
				for (i = i - 1; i >= 0; i--)
					free(args[i]);
			}
			free(args);
			free(buffer);
			malloc_error();
		}
		for (j = j_store, k = 0; NOT_DELIM; j++, k++)
			args[i][k] = buffer[j];
		if (i == (arg_count - 1))
			k--;
		args[i][k] = '\0';
	}
	args[i] = NULL;
	return (args);
}
