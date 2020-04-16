#include "header.h"

/**
 * malloc_error - prints error message and exits when malloc fails
 * @name: the name of our compiled program
 */

void malloc_error(char **name)
{
	/* Error message from malloc man page, exit status from ENOMEM */
	char *string = "ENOMEM Out of memory.";
	free((*name));
	write(STDERR, string, _strlen(string));
	exit(12);
}

/**
 * malloc_error - prints error message and exits when malloc fails
 */
 
void malloc_error2(void)
{
        /* Error message from malloc man page, exit status from ENOMEM */
	 char *string = "ENOMEM Out of memory.";
	 write(STDERR, string, _strlen(string));
}


/**
 * getline_error - prints error message and exits when getline fails
 */

void getline_error(void)
{
	/*Error message from getline man page, exit status from EINVAL */
	perror("EINVAL Bad arguments\n");
	exit(22);
}
/**
 * write_error - a fucntion to wrtie and error if write fails.
 */
void write_error(void)
{
	/* Error message from any function with a write() for if the write fails */
	perror("ERROR: write failed.\n");
	exit(450);
}
