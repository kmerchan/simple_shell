#include "header.h"
#define STDIN STDIN_FILENO

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

ssize_t _getline(char **buffer, size_t *buffsize, FILE *stdin)
{
	ssize_t rd = 0, count = 0;
/*	ssize_t i = 0;
 */
/*	printf("We are in Tim's getline function\n");
 */
	if (buffer == NULL || buffsize == NULL)
		return (-1);

	rd = read(STDIN, *buffer, *buffsize);
	if (rd < 0)
	{
		free(*buffer);
		getline_error();
	}
/*	printf("We have read %zu bytes. Here's what we read:\n", rd);
	write(STDOUT_FILENO, *buffer, rd);
*/
	while (rd == (unsigned)*buffsize)
	{
/*		printf("We need to read more so let's realloc buffer\n");
 */
		count += rd;
/*		printf("count: %zu\n", count);
 */
		*buffer = _realloc(*buffer, count);
		rd = read(STDIN, &(*buffer)[count], *buffsize);
		if (rd < 0)
		{
			free(*buffer);
			getline_error();
		}
/*		printf("We have read %zu bytes. Here's what we read:\n", rd);
		printf("%s\n", *buffer);
*/
	}
	count += rd;
/*	printf("rd: %zu and count: %zu\n", rd, count);
 */
	(*buffer)[count] = '\0';
/*	printf("Now we're going to chop off tailing newline\n");
	while ((*buffer)[i])
	{
		if ((*buffer)[i] == '\n' && (*buffer)[i + 1] == '\0')
			(*buffer)[i] = '\0';
		i++;
	}
*/
/*	printf("The final buffer is:\n%s\n", *buffer);
	printf("All finished with getline, back to Shelly\n");
*/
	return (count);
}
