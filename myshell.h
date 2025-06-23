#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_WORD 10
#define MAX_CHAR 100

extern char **environ;

// Function declarations
char **split(char *line, char *delim);
void remove_spaces(char *s);
int process_line(char *args[], char *line[]);
void remove_endOfLine(char line[]);
int list_environ(void);
void lsh_cd(char **args);
int read_line(char *line[], char *args[], char *outputfile);

#endif
