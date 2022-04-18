#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>

#define EMPTY_STR ""

/**
 * struct CMD - structure for the CMD
 * @command: command used
 * @args: arguments
 * @n_args: number of arguments
 * Return: Always 0
 */

typedef struct CMD
{
	char *command;
	char **args;
	int n_args;
} cmd_t;

char *_strconcat(char *s1, char *s2, char *s3);
char *_strdup(char *str);
int _strlen(const char *str);
int _countby(char *str, char *delimeter);

#endif
