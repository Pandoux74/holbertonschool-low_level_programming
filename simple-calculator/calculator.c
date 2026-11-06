#include <stdio.h>

/**
 * main - Display a simple calculator menu
 * 
 * Return always 0
 */
int main(void)
{
	int choice;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("5) Quit\n");

	printf("Choice: ");
	scanf("%d", &choice);

	if (choice == 9)
	{
		printf("Bye!\n");
	}

	return (0);
}
