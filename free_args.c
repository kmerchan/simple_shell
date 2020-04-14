#include "header.h"

/**
 * free_args - a function to free the args
 * @args: the arguments
 */

void free_args(char ***args)
{
	int i;

	for (i = 0; (*args)[i]; i++)
		free((*args)[i]);
	free((*args)[i]);
	free((*args));
}
