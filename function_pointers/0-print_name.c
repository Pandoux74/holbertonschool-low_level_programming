#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - imprime un nom en utilisant un pointeur de fonction
 * @name: le nom à imprimer
 * @f: pointeur vers la fonction d'affichage
 *
 * Return: Rien
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
