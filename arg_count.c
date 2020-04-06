#include "header.h"

/**
 * arg_counting - function to count number of arguments based on deliminator
 * @buffer: input string to find argument count of
 *
 * @delim: input deliminator separating arguments
 *
 * Return: number of arguments
 */

ssize_t arg_counting(char *buffer, const char *delim)
{
	ssize_t arg_count = 0, i = 0;

	while (buffer[0] == delim[0])
		buffer++;
	if (buffer[0] != '\0')
		arg_count++;
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == delim[0])
		{
			arg_count++;
			while (buffer[i + 1] == delim[0])
				i++;
		}
	}
	return (arg_count);
}
