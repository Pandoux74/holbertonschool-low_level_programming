#include <stdio.h>
/**
 * row_sum - calcule la somme d'une ligne de la table de multiplication
 * @row: le numéro de la ligne (le multiplicateur)
 * @cols: le nombre de colonnes à additionner
 *
 * Return: la somme de row * c pour c allant de 1 à cols
 */
int row_sum(int row, int cols)
{
	int c;
	int sum = 0;

	for (c = 1; c <= cols; c++)
		sum += row * c;

	return (sum);
}
/**
 * total_sum - calcule la somme de toutes les lignes de la table
 * @rows: le nombre de lignes
 * @cols: le nombre de colonnes
 *
 * Return: la somme totale de la table de multiplication
 */
int total_sum(int rows, int cols)
{
	int r;
	int total = 0;
	int current = 0;

	for (r = 1; r <= rows; r++)
	{
		current = row_sum(r, cols);
		total += current;
	}

	return (total);
}
/**
 * main - point d'entrée du programme
 *
 * Return: 0 en cas de succès
 */
int main(void)
{
	printf("%d\n", total_sum(3, 3));
	return (0);
}
