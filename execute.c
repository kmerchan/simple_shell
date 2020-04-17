#include "header.h"

/**
 * execute - forks the process into child to execute program
 * @args: input argv (array of arguments)
 * @path: path is the name
 * @buffer: input buffer read to if need to free
 * Return: The exit status of the child, or errno, or 0 for fall back.
 */

int execute(char **path, char ***args, char **buffer)
{
	pid_t pid;
	int status, ex = 0;

	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	else if (pid < 0)
	{
		free((*path));
		free_args(args);
		free((*buffer));
		perror("");
		return (errno);
	}
	else
	{
		ex = execve((*path), (*args), environ);
		if (ex < 0)
		{
			free((*path));
			free_args(args);
			free((*buffer));
			perror("");
			return (errno);
		}
	}
	return (0);
}
