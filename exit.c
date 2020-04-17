#include "header.h"

/**
 * goodbye - a fucntion to free remaining memory and exit
 * @buffer: the user input string from getline
 * @args: the tokenized array of arguments
 * @sts: input status of previous command
 * @name: name of currently running program
 */

void goodbye(char **buffer, char ***args, int *sts, char **name)
{
	int i;

	for (i = 0; (*args)[i]; i++)
		free((*args)[i]);
	free((*args)[i]);
	free((*args));
	free((*name));
	free((*buffer));

	exit(*sts);
}
