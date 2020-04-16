#include "header.h"

/**
 * check_exec - checks if the program can be executed before fork
 * @path: input double pointer to set path to after checking PATH (environ)
 * @args: input pointer to 2D array of arguments, including program name
 * @buffer: input pointer to buffer read to in getline to free if error called
 * @sts: input status of previous command
 * @lc: input of current line count
 */

void check_exec(char **path, char ***args, char **buffer, int *sts, int lc)
{
	char *count;
	struct stat buf;

	(*path) = checkpath(findpath(), (*args)[0]);
	if ((*path) == NULL)
	{
		free_args(args);
		free((*buffer));
		malloc_error();
	}
	*sts = stat((*path), &buf);
	if ((*sts) != 0)
	{
		count = itoa(lc);
		write(STDERR, count, _strlen(count));
		write(STDERR, ": ", 2);
		write(STDERR, (*args)[0], _strlen((*args)[0]));
		write(STDERR, ": not found\n", 13);
		free(count);
		*sts = 127;
		return;
	}

	*sts = access((*path), X_OK);
	if ((*sts) != 0)
	{
		perror("");
		return;
	}
}

/**
 * itoa - a function to take an int and convert it to
 * a character string for printing.
 * @num: an integer to be converted
 * Return: a pointer to our string output.
 */

char *itoa(int num)
{
	char *string = malloc(sizeof(char) * 10);
	int i = 0, digits = 0, base = 10, divider, pwr, tmp;

	if (num == 0)
		string[i] = '0';
	else if (num < 10)
		string[i] = (num + '0');
	else if (num > 10)
	{
		tmp = num;
		while (tmp != 0)
		{
			tmp /= 10;
			digits++;
		}
		for (pwr = digits; pwr > 0; pwr--, i++)
		{
			divider = power(base, pwr);
			tmp = (num / divider);
			if (tmp < 0)
				tmp *= -1;
			string[i] = (tmp + '0');
			num = (num % divider);
		}
		i--;
	}
	i++;
	string[i] = '\0';
	return (string);
}


/**
 * power - a function to return the length of a string
 * @base: a base for out exponentiation
 * @exp: out exponent
 * Return: returns an int
 */

int power(int base, int exp)
{
	int i = 1;
	int result = 1;

	for (i = 1; i < exp; i++)
		result *= base;

	return (result);
}
