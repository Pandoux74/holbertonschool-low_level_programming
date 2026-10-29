#include <stdio.h>
/**
 * print_table - affiche la table de multiplication de 1 à size
 * @size: la taille de la table (nombre de lignes et de colonnes)
 *
 * Return: rien (la fonction est de type void)
 */
void print_table(int size)
{
	int row, col;

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
		{
			printf("%d ", row * col);
		}
		printf("\n");
	}
}

/**
 * main - point d'entrée du programme
 *
 * Return: 0 en cas de succès
 */

int main(void)
{
	print_table(4);
	return (0);
}
