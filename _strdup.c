#include "header.h"

/**
 * _strdup - a function to copy a string.
 * @input: our argv[0] program name.
 * @name: the name variable
 * Return: a pointer to output.
 */

char *_strdup(char *input, char *name)
{
	int i;

	for (i = 0; input[i]; i++)
	{
		name[i] = input[i];
	}
	name[i] = '\0';

	return (name);
}
