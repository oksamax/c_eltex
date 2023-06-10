#include <stdio.h>
#include <string.h>

void func(char *a, char *b, int(*compare)(const char *, const char *));

int main(void)
{
	char word_1[16] = {0}, word_2[16] = {0};
	int (*ptr)(const char *, const char *);

	printf("Enter word 1:");
	scanf("%s",word_1);
	printf("Enter word 2:");
	scanf("%s",word_2);

	ptr = strcmp;

	func(word_1, word_2, ptr);

	return 0;
}

void func (char *a, char *b, int (*compare)(const char *, const char *))
{
	if(!(*compare)(a,b)) printf("word 1 = word 2\n");
	else printf("word 1 != word 2\n");
}

