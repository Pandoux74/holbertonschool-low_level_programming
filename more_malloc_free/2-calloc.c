#include "main.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * _calloc - Allocates memory for an array
 * @nmemb: Number of elements
 * @size: Size of each element
 *
 * Return: Pointer to allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned char *ptr;
	size_t total;
	size_t i = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);

	if ((size_t)nmemb > SIZE_MAX / size)
		return (NULL);

	total = (size_t)nmemb * size;
	ptr = malloc(total);

	if (ptr == NULL)
		return (NULL);

	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}

	return (ptr);
}
