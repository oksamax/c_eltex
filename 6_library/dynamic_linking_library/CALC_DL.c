#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
	int item = 0, counter = 0, i = 0, counter_2 = 0;
	char library_name[20] = {'0'}, function_name[10][20] = {'0'};
	float variable_a = 0, variable_b = 0;
	void *lib_ptr = NULL;
	float (*func_ptr[10])(float, float);

	printf("***Calculator***\n\n");
	
	do {
		printf("Enter library name (20characters):");
		scanf("%s",library_name);
		
		lib_ptr = dlopen(library_name, RTLD_LAZY);

		if(lib_ptr == NULL) {
			printf("There isn't such library!\n");
		}

	} while (lib_ptr == NULL);

	do {
		printf("\nFormation of calculator functions:\n1.Addition function\n2.Exit\n\nEnter item:");
		scanf("%d",&item);

		if(1 == item){
			
			do {
				printf("Enter function name (20 characters):");
				scanf("%s",function_name[counter]);

				func_ptr[counter] = dlsym(lib_ptr, function_name[counter]); 
				if (NULL == func_ptr[counter]){
					puts("There isn't such function!\n");
				}

			} while (NULL == func_ptr[counter]);
			counter++;
		}
		else if ((2 == item)&&(0 == counter)) {
			printf("You haven't entered any functions!\n");
			item = 3;
		}
		else if (item != 2) printf("There isn't such item!\n");
	} while (item != 2);

	counter++;

	do {
		printf("Menu:\n");
		for(i = 1; i < counter; i++){
			printf("%d. %s\n", i, function_name[i-1]);
		}
		printf("%d. exit\n", i);

		printf("Enter item:");
		scanf("%d",&item);

		if ((item > 0)&&(item < i)){
			printf("Enter varibles a = ");
			scanf("%f",&variable_a);
			printf("Enter varibles b = ");
			scanf("%f",&variable_b);
			printf("Result = %.2f\n", func_ptr[item-1](variable_a,variable_b));
		}
		else if(item != i) printf("You entered the wrong item!\n");
	} while (item != i);

	dlclose(lib_ptr);

	return 0;
}
