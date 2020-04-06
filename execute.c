#include "header.h"

/**
 * execute - forks the process into child to execute program
 * @args: input argv (array of arguments)
 *
 * Return: -1 if failure
 */

int execute(char **args)
{
	pid_t pid;
	int status, ex = 0;

	pid = fork();
	if (pid > 0)
		wait(&status);
	/* several exit codes listed on man page */
	else if (pid < 0)
	{
		perror("ERROR: Could not fork child\n");
		exit(101);
	}
	else
	{
		ex = execve(args[0], args, environ);
		if (ex < 0)
		{
			perror("ERROR: executing the program failed\n");
			exit(102);
		}
	}
	return (ex);
}
