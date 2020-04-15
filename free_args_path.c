#include "header.h"

/**
 * free_args - a function to free the args
 * @args: the arguments
 */

void free_args(char ***args)
{
	int i = 0;

	for (i = 0; (*args)[i]; i++)
		free((*args)[i]);
	free((*args)[i]);
	free((*args));
}

/**
 * free_all_except_buffer - a function to free the path and args
 * @path: the path to free
 * @check_path: path status to check/reset
 * @args: input argument 2D array
 */

void free_all_except_buffer(char **path, int *check_path, char ***args)
{
	if ((*check_path) == 1)
		free(*path);
	(*check_path) = 0;
	free_args(args);
}
