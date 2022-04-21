#ifndef SHELL_
#define SHELL_

#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>

/**
 * struct SHELL - structure for the SHELL
 * @command: command used
 * @args: arguments
 * @n_args: number of arguments
 * Return: Always 0
 */

typedef struct SHELL
{
	char *command;
	char **args;
	int n_args;
} shell_t;

char *_strconcat(char *str1, char *str2, char *str3);
char *_strduplicate(char *str);
int _strlen(const char *str);
int _countby(char *str, char *delimeter);
void new_signal_handler(int pid);
shell_t *new_shell(int n_args);
shell_t *parse_shell(char *input);
void free_struct(shell_t *shell);
int count_args_by_space(char *input);
void free_struct(shell_t *shell);
char *get_path_from_command(shell_t *shell, char *envPath);
void print_dolar_symbol(void);
char *get_user_line(void);

#endif
