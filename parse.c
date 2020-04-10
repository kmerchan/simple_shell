#include "header.h"

#define NOT_DELIM (buffer[j] != delim[0] && buffer[j] != '\0')

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
	ssize_t i = 0, arg_count = 0, j = 0, j_store = 0, arg_size = 0, k = 0;

/*	printf("We are in Kelsie's parse function\n");
 */
	arg_count = arg_counting(buffer, delim);
/*	printf("We have %zu arguments\n", arg_count);
 */
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (args == NULL)
	{
		free(buffer);
		malloc_error();
	}
/*	printf("We have malloced out our rows, corresponding to arg_count\n");
 */
	for (i = 0; i < arg_count; i++, j++)
	{
/*		printf("%s\n", buffer);
 */		for (j_store = j, arg_size = 0; NOT_DELIM; j++)
			arg_size++;
/*		if (i == (arg_count - 1))
			arg_size--;
*/
/*		printf("The size of argument %zu is %zu\n", i, arg_size);
		printf("j_store: %zu and j: %zu\n", j_store, j);
*/
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
/*		printf("We have malloced out row %zu\n", i);
 */
		for (j = j_store, k = 0; NOT_DELIM; j++, k++)
			args[i][k] = buffer[j];
		if (i == (arg_count - 1) && buffer[j - 1] == '\n')
			k--;

		args[i][k] = '\0';
	}
	args[i] = NULL;
/*
	printf("Here is our args array (similar to argv):\n");
	i = 0;
	while (args[i] != NULL)
	{
		printf("%s\n", args[i]);
		i++;
	}
	printf("All finished with parse function, let's go back to Shelly\n");
*/
	return (args);
}
