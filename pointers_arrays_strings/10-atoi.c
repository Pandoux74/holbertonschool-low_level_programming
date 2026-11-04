#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: String to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			do {
				result = result * 10 + (s[i] - '0');
				i++;
			} while (s[i] >= '0' && s[i] <= '9');

			break;
		}

		i++;
	}

	return (result * sign);
}
