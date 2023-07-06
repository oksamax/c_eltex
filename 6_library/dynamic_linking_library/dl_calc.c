#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <malloc.h>

int main(void)
{
	int variable_a = 0, variable_b = 0, *ptr_lib = NULL, (*ptr_func)(int,int);
	char name_lib[10] = {'0'};

	printf("Enter name library:");
	gets(name_lib);

	ptr_lib = dlopen("name_lib", RTLD_LAZY);

	if (NULL == ptr_lib) {
		printf("ERROR OPEN LIBRARY!!!\n");
		exit(1);
	}

	ptr_func = dlsym(ptr_lib, "add");

	printf("1+1 = %d", ptr_func(1,1));

	return 0;
}

	

