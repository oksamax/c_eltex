#include <stdio.h>

enum colors {red, green = 4, yellow, empty};

int main(void)
{
	enum colors pin;

	for(int i = 0; i < 4; i++){
		if (0 == i) pin = red;
		else if (1 == i) pin = green;
		else if (2 == i) pin = yellow;
		else pin = empty;

		switch (pin)
		{
			case 0:
				printf("red\n");
				break;
			case 4:
				printf("green\n");
				break;
			case 5:
				printf("yellow\n");
				break;
			default:
				printf("empty\n");
		}
	}
	
	return 0;
}





