#include <stdio.h>

int main(void)
{
	int variable_a = 0xA3F4DD03;
	
	printf("Variable a = %X\n\n", variable_a);

	printf("First byte = %02X\n", (variable_a & 0xFF));
	printf("Second byte = %02X\n", ((variable_a>>8) & 0xFF));
	printf("Third byte = %02X\n", ((variable_a>>16) & 0xFF));
	printf("Fourth byte = %02X\n\n", ((variable_a>>24) & 0xFF));

	printf("New third byte = %02X, Variable a = %X\n",0x55, ((variable_a & 0xFF00FFFF)|0x550000));

	return 0;
}
