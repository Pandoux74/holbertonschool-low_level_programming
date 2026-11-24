#include "main.h"

/**
 * find_sqrt - Searches for the natural square root
 * @n: The number
 * @i: The current candidate
 *
 * Return: The square root, or -1
 */
static int find_sqrt(int n, int i)
{
	if (i > n / i)
		return (-1);

	if (i * i == n)
		return (i);

	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root
 * @n: The number
 *
 * Return: The square root, or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (0);

	return (find_sqrt(n, 1));
}
