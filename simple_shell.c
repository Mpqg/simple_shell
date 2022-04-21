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
	shell_t *shell;
	char *line = NULL;
	int count = 0;
	char *commandPath = NULL, *envPath;

	envPath = getenv("PATH");

	signal(SIGINT, new_signal_handler);

	while (true)
	{
		commandPath = NULL;
		count++;
		print_dolar_symbol();
		line = get_user_line();
		shell = parse_shell(line);
		free(line);
		if (builtin_shell(shell))
			continue;

		commandPath = get_path_from_command(shell, envPath);
		if (!commandPath)
		{
			printf("%s: command not found\n", shell->command);
			free(commandPath);
			free_struct(shell);
			continue;
		}

		execute_command(shell, commandPath);
		free(commandPath), free_struct(shell);
	}
	return (EXIT_SUCCESS);
}
