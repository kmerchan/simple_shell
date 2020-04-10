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
			return (ourpath);
		}
		else
			j = 0;
		i++;
	}
/* Potential error here if there is no set path, need to check about default of non working path */
	return (NULL);
}

char *checkpath(char **ourpath, char *command)
{
	size_t i = 0;
	int check;
	char *tmpPath;
	struct stat buf;

	if (ourpath == NULL)
		return (command);
	while (ourpath[i] != NULL)
	{
		tmpPath = str_concat(ourpath[i], command);
		check = stat(tmpPath, &buf);
/*		printf("stat = %d\n", check);
 */		if (check == 0)
			return (tmpPath);/*Make sure to free this in shelly with args array*/
		i++;
		free(tmpPath);
	}
/* If we exit the while loop we need to call our Error, cmd not found function. */
	return (command);
}


char *str_concat(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int length1 = 0;
	int length2 = 0;
	int total = 0;
	char *concat;

	if (s1 != NULL)
		length1 += _strlen(s1);
	else
		s1 = "";
	if (s2 != NULL)
		length2 += _strlen(s2) + 1;
	else
		s2 = "";
	total = length1 + length2 + 1;
/*	printf("Now in StrCat, time to Malloc\n");
 */	concat = (char *) malloc(total * (sizeof(char)));
	if (concat == NULL)
	{
		return (NULL);
	}
	else
	{
/*		printf("Malloc for Concat was Successful\n");
 */		for (i = 0; i < length1; i++, j++)
		{
			concat[j] = s1[i];
		}
		concat[j] = '/';
		j++;
		for (i = 0; i < length2; i++, j++)
		{
			concat[j] = s2[i];
		}
		concat[j] = '\0';
/*		printf("Our path is: %s\n", concat);
 */	}
	return (concat);
}
