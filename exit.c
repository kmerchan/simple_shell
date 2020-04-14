#include "header.h"

/**
 * goodbye - a fucntion to free remaining memory and exit
 * @buffer: the user input string from getline
 * @args: the tokenized array of arguments
 */
void goodbye(char **buffer, char ***args)
{
	int i;

	for (i = 0; (*args)[i]; i++)
		free((*args)[i]);
	free((*args)[i]);
	free((*args));
	free((*buffer));

	exit(0);
}