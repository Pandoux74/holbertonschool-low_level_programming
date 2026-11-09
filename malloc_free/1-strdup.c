#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string
 * @str: String to duplicate
 *
 * Return: Pointer to duplicated string, or NULL
 */
char *_strdup(char *str)
{
	char *copy;
	int i = 0;

	if (str == NULL)
	return (NULL);

	while (str[i] != '\0')
	{
	i++;
	}

	copy = malloc(i + 1);

	if (copy == NULL)
	return (NULL);

	i = 0;

	while (str[i] != '\0')
	{
	copy[i] = str[i];
	i++;
	}

	copy[i] = '\0';

	return (copy);
}
