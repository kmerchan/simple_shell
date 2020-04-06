#ifndef HEADER_H
#define HEADER_H

extern char **environ;

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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

/* declaration of function to execute commands with fork, execve */
int execute(char **args);

/* declaration of function to determine string length */
ssize_t _strlen(char *s);

/* declaration of error functions */
void malloc_error(void);
void getline_error(void);

#endif
