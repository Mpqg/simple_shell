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
	/* Variables */
	int i = 0;
	int statusLock;
	char **arg_list;
	int totalCommand;
	pid_t childPid;
	shell_t *shell;
	size_t len = 0;
	ssize_t nread = 0;
	char *line = NULL;
	int count = 0;
	char *commandPath = NULL, *envPath;

	envPath = getenv("PATH");

	/**
	 * SIGINT = Interrupt the process
	 * rewrite default signals handler
	 *
	 * SIG_IGN = Ignore signal.
	 */
	signal(SIGINT, new_signal_handler);

	while (true)
	{
		/* if (NULL) == false*/
		/* if ("") == true*/
		line = NULL;
		commandPath = NULL;
		count++;

		// TODO: What the f*** doing this!!!
		if (isatty(STDIN_FILENO) == 1)
		{
			/**
			 * Print the prompt - "$ "
			 * when failed return (-1)
			 */
			if (write(STDOUT_FILENO, "$ ", 2) == EOF)
				exit(EXIT_FAILURE);
		}
		// TODO: What the f*** doing this!!!

		/* line the input provided by the user*/
		// (len) what function doing this??
		if ((nread = getline(&line, &len, stdin)) == EOF)
		{
			// TODO: What the f*** doing this!!! - Edwin
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			// TODO: What the f*** doing this!!! - Edwin
			exit(EXIT_FAILURE);
		}

		/**
		 * Parse - Proccess a string and
		 * return in the format that I want
		 *
		 * In this case I want is a
		 * struct of type "shell_t"
		 *
		 * Manipulate line(read buffer)
		 */
		shell = parse_shell(line);
		free(line);

		// ----------------------------------- build-in-functions----------------------
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

		// ----------------------------------- build-in-functions----------------------

		// ----------------------------------- no-build-in-functions----------------------

		/**
		 * Extract the command path
		 *
		 */
		commandPath = get_path_from_command(shell, envPath);
		if (!commandPath)
		{
			printf("%s: command not found\n", shell->command);
			free(commandPath);
			free_struct(shell);
			continue;
		}

		// shell->n_args;
		// ([ arg1, arg2, arg3 ]) = 3;
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

		// [command, arg1, arg2, arg3] = 4

		// arg_list = [command] || shell->args = [arg1, arg2, arg3]
		// [1] + [2] = [1, 2];
		// [command, arg1, arg2, arg3]
		// execv(..., arg_list)

		childPid = fork();
		if (childPid == 0)
		{

			execv(commandPath, arg_list);
		}

		wait(&statusLock);

		// implement execv

		// ----------------------------------- no-build-in-functions----------------------

		// Func that free all mallocs
		free(commandPath);
		free_struct(shell);
	}

	return (EXIT_SUCCESS);
}
