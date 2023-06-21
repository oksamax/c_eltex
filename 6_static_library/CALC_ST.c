#include "lib_static_calc.h"
#include <stdio.h>

int main(void)
{
	int variable_a = 0, variable_b = 0; 
	float item = 0;

	do {
		printf("***Calculator***\nMenu:\n1.Additional\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n");
		printf("\nEnter item:");
		scanf("%f",&item);

		if (1 == item) {
			printf("\nEnter variable a: ");
			scanf("%d", &variable_a);
			printf("Enter variable_b: ");
			scanf("%d", &variable_b);
			printf("Addition a and b = %d\n",add(variable_a, variable_b));
		}

		else if (2 == item) {
			printf("\nEnter variable a: ");
			scanf("%d", &variable_a);
			printf("Enter variable_b: ");
			scanf("%d", &variable_b);
			printf("Subtraction a and b = %d\n",sub(variable_a, variable_b));
		}

		else if (3 == item) {
			printf("\nEnter variable a: ");
			scanf("%d", &variable_a);
			printf("Enter variable_b: ");
			scanf("%d", &variable_b);
			printf("Multiplication a and b = %d\n",multi(variable_a, variable_b));
		}

		else if (4 == item) {
			printf("\nEnter variable a: ");
			scanf("%d", &variable_a);
			printf("Enter variable_b: ");
			scanf("%d", &variable_b);
			printf("Division a and b = %d\n",div(variable_a, variable_b));
		}

		else if (item != 5) printf("You entered the wrong item!!!\n");

		printf("\n\n");

	} while (item != 5);

	return 0;
}

