#include "main.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * array_range - Creates an array of integers
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: Pointer to the array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	size_t size;
	size_t i;
	long long count;

	if (min > max)
		return (NULL);

	count = (long long)max - min + 1;

	if ((unsigned long long)count > SIZE_MAX / sizeof(int))
		return (NULL);

	size = (size_t)count;
	array = malloc(size * sizeof(int));

	if (array == NULL)
		return (NULL);

	i = 0;
	while (i < size)
	{
		array[i] = (int)((long long)min + i);
		i++;
	}

	return (array);
}
