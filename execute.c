#include "header.h"

/**
 * execute - forks the process into child to execute program
 * @args: input argv (array of arguments)
 * @path: path is the name
 * @buffer: input buffer read to if need to free
 */

void execute(char **path, char ***args, char **buffer)
{
	pid_t pid;
	int status, ex = 0;

/*	printf("We are in the execute program\n"); */
	pid = fork();
	if (pid > 0)
	{
/*		printf("I'm the parent function, I'm going to wait.\n"); */
		wait(&status);
	}
	else if (pid < 0)
	{
		free((*path));
		free_args(args);
		free((*buffer));
		perror("");
		exit(errno);
	}
	else
	{
/*		printf("I'm a child process. Let's run program: %s\n", path); */
		ex = execve((*path), (*args), environ);
		if (ex < 0)
		{
			free((*path));
			free_args(args);
			free((*buffer));
			perror("");
			exit(errno);
		}
	}
}
