#include "header.h"

#define NOT_DELIM (buffer[j] != delim[0] && buffer[j] != '\0')

/**
 * _parse - function to tokenize arguments or tokenize paths from PATH
 * @buffer: input string to tokenize/separate into arguments
 * @delim: input deliminator to tokenize buffer at specific breakpoints
 * Return: double pointer to 2D argument array of tokenized args or paths
 */

char **_parse(char *buffer, char *delim)
{
	char **args;
	ssize_t i = 0, arg_count = 0, j = 0, j_store = 0, arg_size = 0, k = 0;

	arg_count = arg_counting(&buffer, delim);
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (args == NULL)
		return (NULL);
	for (i = 0; i < arg_count; i++, j++)
	{
		for (j_store = j, arg_size = 0; NOT_DELIM; j++)
			arg_size++;
		args[i] = malloc(sizeof(char) * (arg_size + 1));
		if (args[i] == NULL)
		{
			if (i != 0)
			{
				for (i = i - 1; i >= 0; i--)
					free(args[i]);
			}
			free(args);
			return (NULL);
		}
		for (j = j_store, k = 0; NOT_DELIM; j++, k++)
			args[i][k] = buffer[j];
		if (j_store != 0)
		{
			if (i == (arg_count - 1) && buffer[j - 1] == '\n')
				k--;
		}
		args[i][k] = '\0';
		if (buffer[j] != '\0')
		{
			while (buffer[j + 1] == delim[0] && delim[0] != ':')
				j++;
		}
	}
	args[i] = NULL;
	return (args);
}
