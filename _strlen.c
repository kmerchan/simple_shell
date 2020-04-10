#include "header.h"

/**
 * _strlen - a function to return the length of a string
 * @s: a char pointer passed from main
 * Return: returns an int for the length of s
 */


int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		continue;

	return (len);
}
