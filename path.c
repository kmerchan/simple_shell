#include "header.h"

/**
 * findpath - a function to find the path and break it
 * up to an array of directories.
 * Return: a pointer to the current path.
 */

char **findpath(void)
{
	size_t i = 0, j = 0, check = 0;
	char path[] = "PATH=";
	char colon[] = ":";
	char **ourpath;

	while (environ[i] != NULL)
	{
		check = 0;
		while (environ[i][j] == path[j] && path[j] != '\0')
		{
			j++;
			check++;
		}
		if (check == 5)
		{
			ourpath = _parse(&environ[i][j], colon);
/*			printf("Here is ourpath:\n"); */
/*			for (i = 0; ourpath[i]; i++) */
/*			printf("%s\n", ourpath[i]); */

			if (ourpath == NULL)
				return (NULL);
			return (ourpath);
		}
		else
			j = 0;
		i++;
	}
	ourpath = malloc(sizeof(char) * 1);
	if (ourpath == NULL)
		return (NULL);
	ourpath[0] = '\0';
	return (ourpath);
}
/**
 * checkpath - a function to check that the pathis valid
 * @ourpath: our current path options one at a time
 * @command: our current command form argv[0]
 * Return: a character pointer to the valid path + cmd
 * concatonated
 */
char *checkpath(char **ourpath, char *command)
{
	size_t i = 0;
	int check;
	char *tmpPath;
	struct stat buf;

	if (ourpath == NULL)
		return (NULL);
	while (ourpath[i] != NULL)
	{
		tmpPath = str_concat(ourpath[i], command);
		check = stat(tmpPath, &buf);
/*		printf("stat = %d\n", check); */
		if (check == 0)
		{
			for (i = 0; ourpath[i]; i++)
				free(ourpath[i]);
			free(ourpath[i]);
			free(ourpath);
			return (tmpPath);
		}
		i++;
		free(tmpPath);
	}
	for (i = 0; ourpath[i]; i++)
		free(ourpath[i]);
	free(ourpath[i]);
	free(ourpath);
	tmpPath = malloc(sizeof(char) * (_strlen(command) + 1));
	if (tmpPath == NULL)
		malloc_error();
	for (i = 0; command[i]; i++)
		tmpPath[i] = command[i];
	tmpPath[i] = '\0';
	return (tmpPath);
}

/**
 * str_concat - a function to concatonate two strings
 * @s1: the first string, in this case each option in
 * our path one option at a time.
 * @s2: our command form argv[0]
 * Return: a char pointer to our concatonated string.
 */

char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, length1 = 0, length2 = 0, total = 0;
	char *concat;

/*	printf("This is ourpath[i]: %s\n", s1); */
	if (s1 != NULL)
	{
		length1 += _strlen(s1);
		if (length1 == 0)
			s1 = "";
	}
	else
		s1 = "";
	if (s2 != NULL)
		length2 += _strlen(s2);
	else
		s2 = "";
	total = length1 + length2 + 2;
/*	printf("string1: %s\nlength1: %d\n", s1, length1); */
/*	printf("string2: %s\nlength2: %d\n", s2, length2); */
/*	printf("total: %d\n", total); */
	concat = (char *) malloc(total * (sizeof(char)));
	if (concat == NULL)
		return (NULL);
/*		printf("Malloc for Concat was Successful\n"); */
	for (i = 0; i < length1; i++, j++)
		concat[j] = s1[i];
/*	printf("We've copied over string1\n"); */
	if (j != 0)
	{
		concat[j] = '/';
		j++;
	}
	for (i = 0; i < length2; i++, j++)
	{
		concat[j] = s2[i];
	}
	concat[j] = '\0';
/*	printf("Our path is: %s\n", concat); */

	return (concat);
}
