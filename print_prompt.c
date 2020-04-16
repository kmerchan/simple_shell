#include "header.h"

/**
 * print_prompt - prints the prompt for user input
 * @name: the name of our compiled program
 * Return: 1 if successful to set user_input
 */

int print_prompt(char **name)
{
	char *prompt = "$ ";
	ssize_t w = 0;

	w = write(STDOUT, prompt, _strlen(prompt));
	if (w < 0)
	{
		free((*name));
		write_error();
		return (-1);
	}

	return (1);
}
