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
#include <errno.h>

/* SCRIPTS & DEFINITIONS */
#define STDIN STDIN_FILENO
#define STDOUT STDOUT_FILENO

/* FUNCTION PROTOTYPES */
/* declaration of function to get the lenth of a string */
int _strlen(char *s);

/* declaration of function to read input into buffer (similar: getline) */
ssize_t _getline(char **buffer, ssize_t *buffsize, FILE *stdin, int user_input);
/*declaration of subfunction to reallocate buffer memory */
char *_realloc(char *buffer, size_t count);

/* declaration of function to parse string into tokens (similar: strtok)*/
char **_parse(char *buffer, const char *delim);
/* declaration of subfunction to count number of arguments */
ssize_t arg_counting(char **buffer, const char *delim);

/* declaration of function to reset buffer after parse */
char *reset(char **buffer, char ***args, const char *delim);

/* declaration of fucntion to compare two strings for exact match */
int _strcmp(char *s1, char *s2);

/* declaration of function to check if program can be run before fork*/
void check_execute(char **path, char ***args, char **buffer);

/* declaration of a function to find the current path in environ */
char **findpath(void);
/* declaration of a function to see if path + command exists */
char *checkpath(char **ourpath, char *command);
/* declaration of subfunction to concatonate path with command */
char *str_concat(char *ourpath, char *command);

/* declaration of function to execute commands with fork, execve */
void execute(char **path, char ***args, char **buffer);

/* declaration of a function to print out the enviroment */
void printenv(void);

/* declaration of a function to free allocated memory and exit */
void goodbye(char **buffer, char ***args);

/* declaration of a function to free the alloted memory for args */
void free_args(cahr ***args);

/* declaration of error functions */
void malloc_error(void);
void getline_error(void);
void write_error(void);

#endif
