#include "shell.h"

/**
 * _strconcat - Concatenate 2 string into one
 * @str1: string
 * @str2: string
 * @str3: string
 * Return: result
 */
char *_strconcat(char *str1, char *str2, char *str3)
{
	char *result = NULL;
	unsigned int len, i = 0, current = 0;
	unsigned int x = 0, y = 0, z = 0;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	if (str3 == NULL)
		str3 = "";

	x = _strlen(str1), y = _strlen(str2), z = _strlen(str3);

	len = x + y + z;
	if (len == 0)
		return (NULL);

	result = malloc(sizeof(char) * (len + 1));

	if (result == NULL)
		return (NULL);

	for (current = 0; current < x; current++)
		result[current] = str1[current];
	for (i = 0; i < y; current++, i++)
		result[current] = str2[i];
	for (i = 0; i < z; current++, i++)
		result[current] = str3[i];

	result[current] = '\0';
	return (result);
}

/**
 * _strduplicate - duplicates string
 *
 * @str: string
 * Return: Always 0
 */

char *_strduplicate(char *str)
{
	char *duplicate, *j;
	int len = 0;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	duplicate = malloc(len + 1);
	j = duplicate;

	if (j == NULL)
		return (NULL);

	while (*str)
	{
		*j++ = *str++;
		*j = '\0';
	}

	return (duplicate);
}

/**
 * strlen - String lenght
 * @str: string
 * Return: Always 0
 */
int _strlen(const char *str)
{
	int count = 0;
	if (!str)
		return (count);

	while (str[count])
		count++;

	return (count);
}
