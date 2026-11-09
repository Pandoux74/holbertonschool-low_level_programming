#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Pointer to new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *copy;
	int len1 = 0, len2 = 0;
	int i = 0, j = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	copy = malloc(len1 + len2 + 1);

	if (copy == NULL)
		return (NULL);

	while (i < len1)
	{
		copy[i] = s1[i];
		i++;
	}

	while (j < len2)
	{
		copy[i] = s2[j];
		i++;
		j++;
	}

	copy[i] = '\0';

	return (copy);
}
