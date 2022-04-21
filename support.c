#include "shell.h"
/**
 * get_path_from_command - get the path of the entered command
 * @shell: is a fuction
 * @envPath: string (no estoy segura)
 * Return: path
 */

char *get_path_from_command(shell_t *shell, char *envPath)
{
	char *path = NULL,
		 *token = NULL,
		 *tempEnvPath = NULL;

	struct stat stats;
	if (is_path_command(shell->command))
	{
		return (_strduplicate(shell->command));
	}
	tempEnvPath = _strduplicate(envPath);

	token = strtok(tempEnvPath, ":");
	while (token != NULL)
	{
		path = _strconcat(token, "/", shell->command);

		if (stat(path, &stats) == 0)
			break;

		free(path);
		path = NULL;
		token = strtok(NULL, ":");
	}

	free(tempEnvPath);

	if (!path)
		return (NULL);
	return (path);
}
/**
 * print_dolar_symbol - Prints $ signal and " " or exits the shell
 * Return: Always 0
 */
void print_dolar_symbol(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		if (write(STDOUT_FILENO, "$ ", 2) == EOF)
			exit(EXIT_FAILURE);
	}
}
/**
 * get_user_line - get user line and prints a new line if error
 * Return: Always 0
 */
char *get_user_line(void)
{
	ssize_t length = 0;
	size_t lenbuff = 0;
	char *line = NULL;

	length = getline(&line, &lenbuff, stdin);
	if (length == EOF)
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	return (line);
}
/**
 * builtin_shell - compares if builtin exits
 * @envs: environment variables
 * @shell: structure for the SHELL
 * Return: Always (0)
 */
bool builtin_shell(shell_t *shell, char **envs)
{
	if (strcmp(shell->command, "exit") == 0)
	{
		free_struct(shell);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(shell->command, "env") == 0)
	{
		while (*envs)
		{
			printf("%s\n", *envs);
			envs++;
		}
		free_struct(shell);
		return (true);
	}
	return (false);
}
/**
 * execute_command - function that execute a command and return the status
 * @shell: shell
 * @commandPath: the path of the command that is used
 * Return: Always 0
 */
int execute_command(shell_t *shell, char *commandPath)
{
	char **arg_list;
	int totalCommand;
	int i;
	int statusLock;
	pid_t childPid;

	totalCommand = shell->n_args + 1;

	arg_list = malloc(sizeof(char *) * totalCommand);

	i = 0;
	while (i < totalCommand)
	{
		if (i == 0)
			arg_list[i] = commandPath;
		else
			arg_list[i] = shell->args[i - 1];
		i++;
	}
	childPid = fork();
	if (childPid == 0)
		execv(commandPath, arg_list);

	wait(&statusLock);
	return (statusLock);
}
