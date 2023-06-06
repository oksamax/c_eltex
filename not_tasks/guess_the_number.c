#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));

	int rand_number = 0, number = 0, counter = 0;

	printf("***Guess the number***\n");

	rand_number = rand()%99 + 1;

	do{
		printf("Enter number from 1 to 100:");
		scanf("%d",&number);
		(number > rand_number)? printf("\nnumber > guess number\n") : printf("\nnumber < guess number\n");
		counter++;
	} while (number != rand_number);

	printf("You guessed the number on the %dth try.\n", counter);

	return 0;
}
	
