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
	size_t count;
	size_t i;

	if (min > max)
		return (NULL);

	count = (size_t)((unsigned int)max - (unsigned int)min) + 1;

	if (count == 0 || count > SIZE_MAX / sizeof(int))
		return (NULL);

	array = malloc(count * sizeof(int));

	if (array == NULL)
		return (NULL);

	i = 0;
	while (i < count)
	{
		array[i] = (int)((unsigned int)min + (unsigned int)i);
		i++;
	}

	return (array);
}
