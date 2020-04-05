#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int main(void)
{
	char *buffer;
	int status;
	ssize_t rd;
	pid_t pid;
	char *space = " ";
	char *prompt = "$ ";
	char **args;
	int arg_count = 1;
	int arg_size = 0;
	char *argument;
	int i = 0, j = 0;
	size_t BUFF_SIZE = 1024;
	int check = 0;
/*	char *env[2] = {"PATH=/usr/bin:/bin", NULL};
 */
	write(STDOUT_FILENO, prompt, 2);

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (buffer == NULL)
	{
		perror("ERROR: could not allocate buffer to read\n");
		exit(98);
	}

	rd = getline(&buffer, &BUFF_SIZE, stdin);
	if (rd < 0)
	{
		perror("ERROR: could not read from input\n");
		exit(99);
	}

	while (buffer[j] != '\0')
	{
		if (buffer[j] == ' ')
		{
			arg_count++;
			j++;
			while (buffer[j] == ' ')
				j++;
		}
		else
			j++;
	}

	args = malloc(sizeof(char *) * (arg_count + 1));
	if (args == NULL)
	{
		perror("ERROR: could not allocate tokenization\n");
		exit(100);
	}

	argument = strtok(buffer, space);
	j = 0;
	while (argument[j] != '\0')
	{
		arg_size++;
		j++;
	}
	i = 0;
	args[i] = malloc(sizeof(char) * (arg_size + 1));
	if (args[i] == NULL)
	{
		perror("ERROR: could not allocate tokenization\n");
		exit(100);
	}

	j = 0;
	while (argument[j] != '\0')
	{
		args[i][j] = argument[j];
		j++;
	}
	j--;
	args[i][j] = '\0';

	argument = strtok(NULL, space);
	while (argument != NULL)
	{
		j = 0;
		arg_size = 0;
		while (argument[j] != '\0')
		{
			arg_size++;
			j++;
		}
		i++;
		args[i] = malloc(sizeof(char) * (arg_size + 1));
		if (args[i] == NULL)
		{
			perror("ERROR: could not allocate tokenization\n");
			exit(100);
		}
		j = 0;
		while (argument[j] != '\0')
		{
			args[i][j] = argument[j];
			j++;
		}
		j--;
		args[i][j] = '\0';
		argument = strtok(NULL, space);
	}
	i++;
	args[i] = NULL;

	i = 0;
	j = 0;
	while (args[i] != NULL)
	{
		printf("%s\n", args[i]);
		i++;
		j++;
	}

	pid = fork();
	printf("%d\n", pid);
	if (pid > 0)
		wait(&status);

	else if (pid < 0)
	{
		perror("ERROR: Could not fork child\n");
		exit(101);
	}
	else
	{
		printf("Hi!  I'm a child\n");
		printf("This is args[0]: %s\n", args[0]);
		check = execve(args[0], args, environ);
		if (check < 0)
		{
			perror("ERROR: executing the program failed\n");
			exit(102);
		}
		printf("All finished, back to parent\n");
	}

	return(0);
}
