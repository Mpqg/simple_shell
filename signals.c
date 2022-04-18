/**
 * main - Shell program (entry point)
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[], char **envs)
{
	/* Variables */
	size_t len = 0;
	ssize_t nread = 0;
	char *line = NULL;
	int count = 0;
	struct stat statistics;
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
		// if (NULL) == false
		// if ("") == true
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
		 * struct of type "cmd_t"
		 *
		 * Manipulate line(read buffer)
		 */
		cmd_t *cmd = parse_cmd(line);
		free(line);
		printf("command: |%s|\n", cmd->command);

		// ----------------------------------- build-in-functions----------------------
		if (strcmp(cmd->command, "exit") == 0)
		{
			free_all(cmd);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(cmd->command, "env") == 0)
		{
			while (*envs)
			{
				printf("%s\n", *envs);
				envs++;
			}
			free_all(cmd);
			continue;
		}

		if (strcmp(cmd->command, "cd") == 0)
		{
			printf("I'm cd command\n");
			free_all(cmd);
			continue;
		}

		// ----------------------------------- build-in-functions----------------------

		// ----------------------------------- no-build-in-functions----------------------

		/**
		 * Extract the command path
		 *
		 */
		commandPath = get_path_from_command(cmd, envPath);
		if (!commandPath)
		{
			printf("%s: command not found\n", cmd->command);
			free(commandPath);
			free_all(cmd);
			continue;
		}

		pid_t childPid = fork();
		int statusLock;

		if (childPid == 0)
		{
			// cmd->n_args;
			// ([ arg1, arg2, arg3 ]) = 3;
			int totalCommand = cmd->n_args + 1;

			char **arg_list = malloc(sizeof(char *) * totalCommand);

			int i = 0;
			while (i < totalCommand)
			{
				if (i == 0)
					arg_list[i] = commandPath;
				else
					arg_list[i] = cmd->args[i - 1];
				i++;
			}

			// [command, arg1, arg2, arg3] = 4

			// arg_list = [command] || cmd->args = [arg1, arg2, arg3]
			// [1] + [2] = [1, 2];
			// [command, arg1, arg2, arg3]
			// execv(..., arg_list)
			execv(commandPath, arg_list);
		}

		wait(&statusLock);

		// implement execv

		// ----------------------------------- no-build-in-functions----------------------

		// Func that free all mallocs
		free(commandPath);
		free_all(cmd);
	}

	return (EXIT_SUCCESS);
}
