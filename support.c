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
