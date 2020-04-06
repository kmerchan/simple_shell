#include "header.h"

/**
 * malloc_error - prints error message and exits when malloc fails
 */

void malloc_error(void)
{
	/* Error message from malloc man page, exit status from ENOMEM */
	perror("ENOMEM Out of memory.  Possibly, the application hit the ");
	perror("RLIMIT_AS or RLIMIT_DATA limit described in getrlimit(2).\n");
	exit(12);
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
