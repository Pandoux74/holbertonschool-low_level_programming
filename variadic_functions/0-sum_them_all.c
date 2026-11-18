
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of all its parameters
 * @n: Number of parameters
 *
 * Return: Sum of the parameters, or 0 if n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
    va_list args;
    unsigned int i;
    int somme = 0;

    if (n == 0)
        return (0);

    va_start(args, n);

    for (i = 0; i < n; i++)
    {
        somme += va_arg(args, int);
    }

    va_end(args);

    return (somme);
}
