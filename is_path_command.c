#include "shell.h"
/**
 * is_path_command - routing command
 * @command:command used
 */
bool is_path_command(char *command)
{
    int i = 0;
    while (command[i])
    {
        if (command[i] == '/')
            return (true);
        i++;
    }
    return (false);
}

/**
 * remove_spaces - removes the spaces before the command
 * @command:command used
 */
char *remove_spaces(char *command)
{
    int i = 0, j = 0;
    while (command[i])
    {
        if (command[i] != ' ')
            command[j++] = command[i];
        i++;
    }
    command[j] = '\0';
    return (command);
}