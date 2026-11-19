#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two numbers passed as arguments
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int a;
	int b;
	int resultat;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	resultat = a * b;

	printf("%d\n", resultat);

	return (0);
}
