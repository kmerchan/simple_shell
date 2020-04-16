#include "header.h"

/**
 * reset - resets buffer if multiple arguments or commands
 * @buffer: input buffer read to in _getline function
 *
 * @args: input 2D array of arguments for first command
 *
 * @delim: input string with the delimiter used to set args
 *
 * Return: new pointer to buffer, starts from next command or NULL
 */

char *reset(char **buffer, char ***args, char *delim)
{
	char *tempbuffer = (*buffer);
	char *newbuffer;
	int i = 0, j = 0;

	for (i = 0; (*args)[i]; i++)
	{
		while (tempbuffer[0] == delim[0])
		       /*|| tempbuffer[0] == '\n') */
			tempbuffer++;
		for (j = 0; (*args)[i][j]; j++)
			tempbuffer++;
		while (tempbuffer[0] == delim[0] || tempbuffer[0] == '\n')
			tempbuffer++;
	}
	if (tempbuffer[0] == '\0')
	{
		free((*buffer));
		return (NULL);
	}
	newbuffer = malloc(sizeof(char) * (_strlen(tempbuffer) + 1));
	if (newbuffer == NULL)
	{
		free((*buffer));
		free_args(args);
		malloc_error2();
	}
	for (i = 0; tempbuffer[i] != '\0'; i++)
		newbuffer[i] = tempbuffer[i];
	newbuffer[i] = '\0';
	free((*buffer));

	return (newbuffer);
}
