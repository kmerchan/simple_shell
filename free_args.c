#include "header.h"

/**
 * free_args - frees all rows of args and args itself
 * @args: pointer to 2D array of arguments
 *
 */

void free_args(char ***args)
{
	int i = 0;

/*	printf("We're in free_args\n");
 */	for (i = 0; (*args)[i]; i++)
		free((*args)[i]);
	free((*args)[i]);
	free((*args));
/*	printf("Args array is free\n");
 */	return;
}
