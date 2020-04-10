#ifndef HEADER_H
#define HEADER_H

extern char **environ;

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

/* SCRIPTS & DEFINITIONS */

/* FUNCTION PROTOTYPES */
/* declaration of function to read input into buffer (similar: getline) */
ssize_t _getline(char **buffer, size_t *buffsize, FILE *stdin);
/*declaration of subfunction to reallocate buffer memory */
char *_realloc(char *buffer, size_t count);
/* declaration of function to parse string into tokens (similar: strtok)*/
char **_parse(char *buffer, const char *delim);
/* declaration of subfunction to count number of arguments */
ssize_t arg_counting(char *buffer, const char *delim);
/* declaration of a function to find the current path in environ */
char **findpath(void);
/* declaration of a function to see if path + command exists */
char * checkpath(char **ourpath, char *command);
/* declaration of function to concatonate path with command */
char * str_concat(char *ourpath, char * command);
/* declaration of function to get the lenth of a string */
int _strlen(char *s);
/* declaration of function to execute commands with fork, execve */
int execute(char **args, char *path);


/* declaration of error functions */
void malloc_error(void);
void getline_error(void);

#endif
