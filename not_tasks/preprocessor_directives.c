#include <stdio.h>

#define LEFT 1
#define RIGHT 0

#define ONE 1
#define TWO ONE+ONE
#define THREE ONE+TWO

#define E_S "Standard ERROR!!!\n\
	example\n"

#define ABS(a) (a) < 0 ? -(a) : (a)

#define value 3

#define DEBUG 1

int main(void)
{
	printf("LEFT=%d RIGHT=%d LEFT+1=%d\n", LEFT, RIGHT, LEFT+1);
	printf("%d %d %d\n", ONE, TWO, THREE);
	printf(E_S);
	printf("Absolute value %d %d\n", ABS(-10), ABS(10));

#if value >= 5
	printf("value >= 5\n");
#elif value <= 3
	#if TWO == 2
		printf("value <= 3\n");
	#endif

#else 
	printf("3 < value < 5\n");
#endif

#ifdef LEFT
	printf("LEFT DEFINED!!!\n");
#elif RIGHT
	printf("RIGHT DEFINED!!!\n");
#else
	printf("LEFT AND RIGHT ARE NOT DEFINED\n");
#endif

#if defined DEBUG
	printf("line=%d, file=%s, func=%s, date=%s, time=%s\n",__LINE__, __FILE__, __func__, __DATE__, __TIME__);
#endif

#line 100 "example"
	printf("line=%d, file=%s, func=%s, date=%s, time=%s\n",__LINE__, __FILE__, __func__, __DATE__, __TIME__);

	return 0;
}
