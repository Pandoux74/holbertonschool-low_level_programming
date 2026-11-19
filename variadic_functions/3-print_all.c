#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a character
 * @args: List of arguments
 */
void print_char(va_list *args)
{
	printf("%c", va_arg(*args, int));
}

/**
 * print_int - Prints an integer
 * @args: List of arguments
 */
void print_int(va_list *args)
{
	printf("%d", va_arg(*args, int));
}

/**
 * print_float - Prints a float
 * @args: List of arguments
 */
void print_float(va_list *args)
{
	printf("%f", va_arg(*args, double));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 */
void print_string(va_list *args)
{
	char *str = va_arg(*args, char *);

	if (str == NULL)
		str = "(nil)";

	printf("%s", str);
}

/**
 * print_all - Prints anything
 * @format: List of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *separator = "";
	const char *types = "cifs";

	void (*printers[])(va_list *) = {
		print_char, print_int, print_float, print_string
	};

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		j = 0;

		while (types[j] != '\0')
		{
			if (format[i] == types[j])
			{
				printf("%s", separator);
				printers[j](&args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
