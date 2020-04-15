#include "header.h"

/**
 * printenv - a function to print out the current enviroment
 * @buffer: buffer with input read into shell
 * @args: 2D array with arguments, including program name
 * @sts: input status of previous command
 *
 */

void printenv(char **buffer, char ***args, int *sts)
{
	int i = 0;
	ssize_t  w;
	char newline[] = "\n";

	(void)buffer;
	(void)args;

	*sts = 0;
	if (environ == NULL)
	{
		perror("ERROR: Enviroment unset or unrecognized.\n");
		return;
	}
	while (environ[i] != NULL)
	{
		w = write(STDOUT, environ[i], _strlen(environ[i]));
		if (w < 0)
			write_error();
		w = write(STDOUT, newline, _strlen(newline));
		if (w < 0)
			write_error();
		i++;
	}
}
