#include "header.h"

/**
 * _strcmp - compares two strings
 * @s1: input string 1
 * @s2: input string 2
 * Return: integer
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (-1);
}
