#include "header.h"

/**
 * arg_counting - function to count number of arguments based on deliminator
 * @buffer: input string to find argument count of
 *
 * @delim: input deliminator separating arguments
 *
 * Return: number of arguments
 */

ssize_t arg_counting(char **buffer, char *delim)
{
	ssize_t arg_count = 0, i = 0;

	while ((*buffer)[0] == delim[0] && delim[0] != ':')
	{
		(*buffer)++;
	}
	if ((*buffer)[0] != '\0' || delim[0] == ':')
	{
		arg_count++;
		if (delim[0] == ':' && _strcmp((*buffer), "\0") == 0)
			return (arg_count);
	}
	for (i = 0; (*buffer)[i]; i++)
	{
		if ((*buffer)[i] == '\n' && i != 0)
		{
			(*buffer)[i] = delim[0];
			break;
		}
		if ((*buffer)[i] == delim[0])
		{
			arg_count++;
			while ((*buffer)[i + 1] == delim[0] && delim[0] != ':')
				i++;
			if ((*buffer)[i + 1] == '\n' || (*buffer)[i + 1] == '\0')
			{
				(*buffer)[i + 1] = delim[0];
				arg_count--;
				return (arg_count);
			}
		}
	}
	return (arg_count);
}
