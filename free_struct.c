#include "shell.h"

/**
 * free_all - free all the structure CMD
 *
 * @cmd: name of the structure
 * Return: Always 0
 */

void free_all(cmd_t *cmd)
{
	int i = 0;

	if (cmd)
	{
		free(cmd->command);
		cmd->command = NULL;

		if (cmd->args)
		{
			for (; i < cmd->n_args; i++)
			{
				if (cmd->args[i])
					free(cmd->args[i]);
			}
			free(cmd->args);
			cmd->args = NULL;
		}
		free(cmd);
		cmd = NULL;
	}
}
