#include "header.h"

/**
 * check_execute - checks if the program can be executed before fork
 * @path: input double pointer to set path to after checking PATH (environ)
 *
 * @args: input pointer to 2D array of arguments, including program name
 *
 * @buffer: input pointer to buffer read to in getline to free if error called
 *
 */

void check_execute(char **path, char ***args, char **buffer)
{
	int check = 0;
	struct stat buf;

	(*path) = checkpath(findpath(), (*args)[0]);
	if ((*path) == NULL)
	{
		free_args(args);
		free((*buffer));
		malloc_error();
	}
/*	printf("Here's how Shelly sets path\n");
	printf("%s\n", (*path));
*/
	check = stat((*path), &buf);
	if (check != 0)
	{
		free_args(args);
		free((*buffer));
		perror("");
		exit(errno);
	}

	check = access((*path), X_OK);
	if (check != 0)
	{
		free_args(args);
		free((*buffer));
		perror("");
		exit(errno);
	}
  
	return;
}
