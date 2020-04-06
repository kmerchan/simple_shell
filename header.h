#ifndef HEADER_H
#define HEADER_H

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
ssize_t _getline(char **buffer, size_t BUFF_SIZE, FILE *stdin);

/* declaration of function to parse string into tokens (similar: strtok)*/
char **_parse(char *buffer, const char *delim);

#endif
