#include "shell.h"

/**
 * parse_shell - parse what you enter(creo)
 * @input: str
 * Return: in fuction shell
 */

shell_t *parse_shell(char *input)
{
	int i = 0, args_count = 0;
	shell_t *shell = NULL;
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

	shell = new_shell(args_count);
	if (!shell)
		return NULL;

	if (shell->n_args == 0)
	{
		shell->command = _strduplicate(input);
		return (shell);
	}
	// Input: ls -l -a -b
	// command = [ls] [-l] [-a] [-b]

	token = strtok(input, " ");
	while (token != NULL)
	{
		if (shell->command == NULL)
			shell->command = _strduplicate(token);

		else
			shell->args[i] = _strduplicate(token), i++;

		token = strtok(NULL, " ");
	}

	return (shell);
}
