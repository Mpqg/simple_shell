#include "shell.h"
/**
 * main - Shell program (entry point)
 * @argc: number of arguments to be passed after execution
 * @argv: list of arguments (where they are hosted)
 * @envs: environment variables
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)),
		 char *argv[] __attribute__((unused)),
		 char **envs)
{
	int i = 0;
	int statusLock;
	char **arg_list;
	int totalCommand;
	pid_t childPid;
	shell_t *shell;
	size_t lenbuff = 0;
	char *line = NULL;
	int count = 0;
	char *commandPath = NULL, *envPath;

	envPath = getenv("PATH");

	signal(SIGINT, new_signal_handler);

	while (true)
	{
		line = NULL;
		commandPath = NULL;
		count++;
		print_dolar_symbol();


		get_user_line();
		length = getline(&line, &lenbuff, stdin);
		if (length == EOF)
		{
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		shell = parse_shell(line);
		free(line);
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
			continue;
		}
		if (strcmp(shell->command, "cd") == 0)
		{
			printf("I'm cd command\n");
			free_struct(shell);
			continue;
		}
		commandPath = get_path_from_command(shell, envPath);
		if (!commandPath)
		{
			printf("%s: command not found\n", shell->command);
			free(commandPath);
			free_struct(shell);
			continue;
		}
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
		free(commandPath), free_struct(shell);
	}
	return (EXIT_SUCCESS);
}
