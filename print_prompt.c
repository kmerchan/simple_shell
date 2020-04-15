#include "header.h"

/**
 * print_prompt - prints the prompt for user input
 * Return: 1 if successful to set user_input
 */

int print_prompt(void)
{
	char *prompt = "$ ";
	ssize_t w = 0;

	w = write(STDOUT, prompt, _strlen(prompt));
	if (w < 0)
	{
		write_error();
		return (-1);
	}

	return (1);
}
