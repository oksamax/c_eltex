#include <stdio.h>

struct test {
	char a;
	int b;
};

struct test1 {
	char a;
	int b;
} __attribute__((packed));


int main(void)
{
	struct test test_no_packed, *ptr_no_packed;
	struct test1 test1_packed, *ptr_packed;
	char str[10] = {'A',0,0,0,0,'B',0,0,0,0};
	char str1[16] = {'A',0,0,0,0,0,0,0,'B',0,0,0,0,0,0,0};

	printf("sizeof(test_no_packed) = %ld\n", sizeof(test_no_packed));
	printf("sizeof(test1_packed) = %ld\n", sizeof(test1_packed));

	ptr_no_packed = (struct test *)str1;
	printf("No packing struct:\n%c %d\n", ptr_no_packed -> a, ptr_no_packed -> b);
	ptr_no_packed++;
	printf("%c %d\n", ptr_no_packed -> a, ptr_no_packed -> b);

	ptr_packed = (struct test1 *)str;
	printf("Packing stuct:\n%c %d\n", (ptr_packed) -> a, (ptr_packed) -> b);
	printf("%c %d\n", (ptr_packed + 1) -> a, (ptr_packed + 1) -> b);




	return 0;
}
