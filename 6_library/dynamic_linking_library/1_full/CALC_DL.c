#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
	int item = 0, counter = 0, i = 0;
	char library_name[20] = {'0'}, function_name[20] = {'0'};
	float variable_a = 0, variable_b = 0;
	void *lib_ptr = NULL;
	float (*func_ptr[10])(float, float);

	puts("***Calculator***");
	
	do {
		puts("Enter library name (20characters):");
		fgets(library_name, 20, stdin);
		lib_ptr = dlopen(library_name, RTLD_LAZY);

		if(lib_ptr == NULL) {
			puts("There isn't such library!\n");
		}
	} while (lib_ptr);

	do {
		puts("Formation of calculator functions:\n1.Addition function 2.Exit\n Enter item:");
		scanf("%d",item);

		if(1 == item){
			
			do {
				puts("Enter function name (20 characters):");
				fgets(function_name, 10, stdin);
				func_ptr[counter] = dlsym(lib_ptr, dunction_name); 
				if (NULL == func_ptr[counter]){
					puts("There isn't such function!\n");
				}
			} while (func_ptr[counter]);
			
			counter++;
		}
		else if ((2 == item)&&(0 == counter)) {
			puts("You haven't entered any functions!\n");
			item = 3;
		}
		else puts("There isn't such item!\n");
	} while (2 == item);


	counter++;
	do {
		puts("Menu:\n");
		for(i = 1; i < counter; i++){
			printf("%d. %s\n", i, function_name[i-1]);
		}
		printf("%d. exit\n", i);

		if ((item > 0)||(item < i)){
			puts("Enter varibles a = ");
			scanf("%f",variables_a);
			puts("Enter varibles b = ");
			scanf("%f",variables_b);
			printf("Result = %f\n", func_ptr[item](variables_a,variables_a));
		}
		else if(item != i) puts("You entered the wrong item");
	} while (item != i);


	dlclose(lib_ptr);

	return 0;
}
