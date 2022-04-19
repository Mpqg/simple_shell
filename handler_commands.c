#include "shell.h"

/**
 * new_shell - (no se)
 * @n_args: number the arguments
 * Return: shell
 */

shell_t *new_shell(int n_args)
{
	shell_t *shell = (shell_t *)malloc(sizeof(shell_t));
	if (!shell)

		return (NULL);

	shell->n_args = n_args;
	shell->command = NULL;
	shell->args = NULL;

	shell->args = (char **)malloc(sizeof(char *) * n_args);
	if (shell->args == NULL)
	{
		free_struct(shell);
		return (NULL);
	}
	return (shell);
}
