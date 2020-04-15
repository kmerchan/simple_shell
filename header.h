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

/* STRUCTS & DEFINITIONS */
#define STDIN STDIN_FILENO
#define STDOUT STDOUT_FILENO
#define STDERR STDERR_FILENO

/**
 * struct get_program - matches input command to builtin or sends to execute
 * @name: name of the built-in or newline
 * @func: function pointer to built-in
 *
 */

typedef struct get_program
{
	char *name;
	void (*func)(char **buffer, char ***args, int *sts);
} get_program;

/* FUNCTION PROTOTYPES */
/* declaration of function to get the lenth of a string */
int _strlen(char *s);

/* decalration of function to print prompt for user input */
int print_prompt(void);

/* declaration of function to read input into buffer (similar: getline) */
ssize_t _getline(char **buffer, ssize_t *buffsize, FILE *stdin,
		 int user_input, int stat_check);
/*declaration of subfunction to reallocate buffer memory */
char *_realloc(char *buffer, size_t count);

/* declaration of function to parse string into tokens (similar: strtok)*/
char **_parse(char *buffer, char *delim);
/* declaration of subfunction to count number of arguments */
ssize_t arg_counting(char **buffer, char *delim);

/* declaration of function to reset buffer after parse */
char *reset(char **buffer, char ***args, char *delim);

/* declaration of fucntion to compare two strings for exact match */
int _strcmp(char *s1, char *s2);

/* declaration of a function to print out the enviroment */
void printenv(char **buffer, char ***args, int *sts);

/* declaration of a function to free allocated memory and exit */
void goodbye(char **buffer, char ***args, int *sts);

/* declaration of a function to continue if input is newline */
void newline(char **buffer, char ***args, int *sts);

/* declaration of function to check if program can be run before fork*/
void check_exec(char **path, char ***args, char **buffer, int *sts, int lc);
/* declaration of subfunction to change integer to string for error */
char *itoa(int num);
/* declaration of subfunction to find power of base raised to exp */
int power(int base, int exp);

/* declaration of a function to find the current path in environ */
char **findpath(void);
/* declaration of a function to see if path + command exists */
char *checkpath(char **ourpath, char *command);
/* declaration of subfunction to concatonate path with command */
char *str_concat(char *ourpath, char *command);

/* declaration of function to execute commands with fork, execve */
void execute(char **path, char ***args, char **buffer);

/* declaration of a function to free the alloted memory for args */
void free_args(char ***args);
/* declaration of a function to free the alloted memory for path */
void free_all_except_buffer(char **path, int *check_path, char ***args);

/* declaration of error functions */
void malloc_error(void);
void getline_error(void);
void write_error(void);

#endif
