#include "header.h"
#define last (*buffer)[count - 1]

/**
 * _getline - is a function meant to read input from STDIN and
 * copy it into a buffer. The fuction should also check for errors
 * in reading, realloc if the input exceeds the buffer and return
 * a count of all it added into the buffer.
 * @buffer: a pointer to the buffer allocated in our shelly.c
 * @buffsize: the size of the buffer from shelly.c 1024 expected.
 * @stdin: take input from standard in
 * Return: number of bytes read
 */

ssize_t _getline(char **buffer, ssize_t *buffsize, FILE *stdin, int user_input, int stat_check)
{
	ssize_t rd = 0, count = 0;
	char newline[1] = {'\n'};
	(void)stdin;

/*	printf("We are in Tim's getline function\n");
 */
	if (buffer == NULL || buffsize == NULL)
	{
		free((*buffer));
		getline_error();
	}
	rd = read(STDIN, *buffer, *buffsize);
	if (rd < 0)
	{
		free((*buffer));
		getline_error();
	}
	else if (rd == 0)
	{
		free((*buffer));
		if (user_input)
			write(STDOUT, newline, _strlen(newline));
		exit(stat_check);
	}
/*	printf("We have read %ld bytes. Here's what we read:\n", rd);
	write(STDOUT_FILENO, *buffer, rd);
*/
	count += rd;
	while (rd == *buffsize && last != '\0' && last != '\n')
	{
/*		printf("We need to read more so let's realloc buffer\n");
		printf("count: %ld\n", count);
 */
		*buffer = _realloc(*buffer, count);
		rd = read(STDIN, &(*buffer)[count], *buffsize);
		if (rd < 0)
		{
			free(*buffer);
			getline_error();
		}
		else if (rd == 0)
		{
			break;
		}
/*		printf("We have read %ld bytes. Here's what we read:\n", rd);
		printf("%s\n", *buffer);
*/		count += rd;
	}

/*	printf("rd: %ld and count: %ld\n", rd, count);
 */
	(*buffer)[count] = '\0';
/*	printf("The final buffer is:\n%s\n", *buffer);
	printf("All finished with getline, back to Shelly\n");
*/
	return (count);
}
