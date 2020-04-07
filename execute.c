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

	printf("We are in the execute program\n");
	pid = fork();
	if (pid > 0)
	{
		printf("I'm the parent function, I'm going to wait.\n");
		wait(&status);
	}
	else if (pid < 0)
	{
	/* several exit codes listed on man page */
		perror("ERROR: Could not fork child\n");
		exit(101);
	}
	else
	{
		printf("I'm a child process. Let's run program: %s\n", args[0]);
		ex = execve(args[0], args, environ);
		if (ex < 0)
		{
			perror("ERROR: executing the program failed\n");
			exit(102);
		}
	}
	return (ex);
}
