cmd_t *parse_cmd(char *input)
{
	int i = 0, args_count = 0;
	cmd_t *cmd = NULL;
	char *token = NULL;

	/**
	 * Remove the "\n" of the end
	 * from the variable - (line)
	 *
	 * Example:
	 *  input - "hola\n" and should
	 * 	be "hola"... Without the break line
	 */
	/** Remove the last character '\n' for '\0' */
	if (input[strlen(input) - 1] == '\n')
		input[strlen(input) - 1] = '\0';

	/**
	 * Return the count of the args
	 * each arg its separated by space
	 *
	 * Example:
	 * - ["ls", "-l", "-a", "-b"]
	 * Output: 3
	 */
	args_count = count_args_by_space(input);

	cmd = new_cmd(args_count);
	if (!cmd)
		return NULL;

	if (cmd->n_args == 0)
	{
		cmd->command = _strdup(input);
		return (cmd);
	}
	// Input: ls -l -a -b
	// command = [ls] [-l] [-a] [-b]

	token = strtok(input, " ");
	while (token != NULL)
	{
		if (cmd->command == NULL)
			cmd->command = _strdup(token);

		else
			cmd->args[i] = _strdup(token), i++;

		token = strtok(NULL, " ");
	}

	return (cmd);
}
