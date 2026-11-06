#include <stdio.h>

/**
 * main - Display a simple calculator menu
 * 
 * Return always 0
 */
int main(void)
{
	int choice;
	int A;
	int B;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	printf("Choice: ");
	scanf("%d", &choice);

	if (choice == 4)
	{
		printf("A: ");
		scanf("%d", &A);

		printf("B: ");
		scanf("%d", &B);

		printf("Result: %d\n", A / B);
	}

	return (0);
}
