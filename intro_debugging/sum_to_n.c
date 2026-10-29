#include <stdio.h>
/**
 * sum_to_n - calcule la somme des entiers de 0 à n
 * @n: le nombre jusqu'auquel on additionne
 *
 * Return: la somme obtenue
 */
int sum_to_n(int n)
{
	int i;
	int sum = 0;

	for (i = 1; i <= n; i++)
		sum += i;

	return (sum);
}

/* -- trace a simple loop and verify a function’s return value -- */
/**
 * main - point d'entrée du programme
 *
 * Return: 0 en cas de succès
 */
int main(void)
{
	printf("%d\n", sum_to_n(10));
	return (0);
}
