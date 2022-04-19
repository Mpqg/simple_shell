#include "shell.h"

/**
 * free_struct - free all the structure shell
 *
 * @shell: name of the structure
 * Return: Always 0
 */

void free_struct(shell_t *shell)
{
	int i = 0;

	if (shell)
	{
		free(shell->command);
		shell->command = NULL;

		if (shell->args)
		{
			for (; i < shell->n_args; i++)
			{
				if (shell->args[i])
					free(shell->args[i]);
			}
			free(shell->args);
			shell->args = NULL;
		}
		free(shell);
		shell = NULL;
	}
}
