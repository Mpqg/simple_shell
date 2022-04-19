#include "shell.h"
/**
 * count_args_by_space - split and count of arguments
 * 
 * @input: text to be separated
 * Return: Always 0
 */
int count_args_by_space(char *input)
{
	int count = 0;

	/**
	 * Duplicate the "input" variable
	 * for non modificated.
	 *
	 * Because the function strtok() modified
	 * the variable that provide.
	 *
	 * And the end make a free for the
	 * variable duplicated "duplicate"
	 */

	char *duplicate = _strduplicate(input);
	char *token = strtok(duplicate, " ");

	while (token != NULL)
		count++, token = strtok(NULL, " ");

	/**
	 * Make a count of all input
	 * included the command
	 *
	 * ["ls", "-l", "-a", "-b"] = 4
	 *
	 * And put -1 for ignoring the command
	 * ["-l", "-a", "-b"] = 3
	 *
	 * (-1) because ignoring the command
	 */

	//  = condition ? case true : case false;
	if (count >= 1)
	count = count - 1;
	
	free(duplicate);

	return (count);
}
