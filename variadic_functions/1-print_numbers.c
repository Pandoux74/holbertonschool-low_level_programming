
#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Prints numbers followed by a new line
 * @separator: String printed between numbers
 * @n: Number of integers to print
 *
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;

    va_start(args, n);

    for (i = 0; i < n; i++)
    {
        if (i > 0 && separator != NULL)
            printf("%s", separator);

        printf("%d", va_arg(args, int));
    }

    va_end(args);
    printf("\n");
}
