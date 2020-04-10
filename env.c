#include "header.h"
#define STDOUT STDOUT_FILENO

/**
 * printenv - a function to print out the current enviroment.
 * Return: a 0 for success or a -1 for failure.
 */

void printenv(void)
{
	int i = 0;
	ssize_t  w;
	char nl[1] = {'\n'};

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
		w = write(STDOUT, nl, 1);
		if (w < 0)
			write_error();
		i++;
	}
}
