#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct str_data {
	char firstname[20];
	char surname[20];
	char number[20];
};

int main(void)
{
	struct str_data *ptr_data = NULL;
	float item;
	int end_counter = 0, counter = 0, i = 0, start = 1;
	char *find_delete_firstname;

	do {
		
		printf("***Telephone directory***\nMenu:\n1. Add user\n2. List of users\n3. Find user\n4. Delete user\n5. Exit\n\nEnter item:");
		scanf("%f",&item);

		//Add user
		if(1 == item) {
			if (1 == start){
				ptr_data = malloc(sizeof(struct str_data));
				
				if (ptr_data == NULL) {
					printf("Dynamic memory not allocated!\n");
					exit(EXIT_FAILURE);
				}
				
				do {
					printf("Enter firstname (from 1 to 20 characters): ");
					scanf("%s",ptr_data->firstname);
				} while (strlen(ptr_data->firstname) > 20);

				do {
					printf("Enter surname (from 1 to 20 characters): ");
					scanf("%s",ptr_data->surname);
				} while (strlen(ptr_data->surname) > 20);

				do {
					printf("Enter number (from 1 to 20 characters): ");
					scanf("%s",ptr_data->number);
				} while (strlen(ptr_data->number) > 20);
				
				end_counter++;
				start = 0;
			}
			
			else if (end_counter != 10) {
				ptr_data = realloc( ptr_data, (end_counter+1) * sizeof(struct str_data));

				if (ptr_data == NULL) {
					printf("Dynamic memory not allocated!\n");
					exit(EXIT_FAILURE);
				}

				do {
					printf("Enter firstname (from 1 to 20 characters): ");
					scanf("%s",(ptr_data + end_counter) -> firstname);
				} while (strlen((ptr_data + end_counter) -> firstname) > 20);

				do {
					printf("Enter surname (from 1 to 20 characters): ");
					scanf("%s",(ptr_data + end_counter) -> surname);
				} while (strlen((ptr_data + end_counter) -> surname) > 20);

				do {
					printf("Enter number (from 1 to 20 characters): ");
					scanf("%s",(ptr_data + end_counter) -> number);
				} while (strlen((ptr_data + end_counter) -> number) > 20 );

				end_counter++;
			}
			else printf("Telephone directory is full!!!\n");
		}

		// List of users
		else if(2 == item) {
			if (end_counter != 0) {
				for(i = 0; i < end_counter; i++) {
					printf("%d. Firstname:%s  Surname:%s Number:%s\n",i+1,(ptr_data + i) -> firstname, (ptr_data + i) -> surname, (ptr_data + i) -> number);
				}
			}
			else printf("Telephone directory is empty!!!\n");
		}

		// Find user
		else if(3 == item) {
			if (end_counter != 0) {
				find_delete_firstname = calloc(20, sizeof(char));

				if (find_delete_firstname == NULL) {
					printf("Dynamic memory not allocated!!!\n");
					exit(EXIT_FAILURE);
				}
				
				do {
					printf("Enter firstname:");
					scanf("%s",find_delete_firstname);
				} while (strlen(find_delete_firstname) > 20);

				for(i = 0; i < end_counter; i++) {
					if (!(strcmp((ptr_data + i) -> firstname, find_delete_firstname))) {
						printf("Firstname:%s Surname:%s Number:%s\n",(ptr_data + i) -> firstname, (ptr_data + i) -> surname, (ptr_data + i) -> number);
						counter++;
					}
				}

				if (0 == counter) printf("User not found!\n");
				counter = 0;
				free (find_delete_firstname);
			}
			else printf("Telephone directory is empty!!!\n");
		}

		// Delete user
		else if(4 == item){
			if (end_counter != 0){
				find_delete_firstname = calloc(20, sizeof(char));

				if (find_delete_firstname == NULL) {
					printf("Dynamic memory not allocated!!!\n");
					exit(EXIT_FAILURE);
				}

				do {
					printf("Enter firstname:");
					scanf("%s", find_delete_firstname);
				} while (strlen(find_delete_firstname) > 20);

				for(i = 0; i < end_counter; i++){
					if(!(strcmp((ptr_data + i) -> firstname, find_delete_firstname))){
						printf("Delete user %s!\n",(ptr_data + i) -> firstname);
						
						strcpy((ptr_data + i) -> firstname, (ptr_data + end_counter - 1) -> firstname);
						strcpy((ptr_data + i) -> surname, (ptr_data + end_counter - 1) -> surname);
						strcpy((ptr_data + i) -> number, (ptr_data + end_counter - 1) -> number);
						
						end_counter--;
						i--;
						ptr_data = realloc(ptr_data, (end_counter)*sizeof(struct str_data));

						if (ptr_data == NULL){
							printf("Dynamic memory not allocated!!!\n");
							exit(EXIT_FAILURE);
						}
					}
				}

				free(find_delete_firstname);
			}
			else printf("Telephone directory is empty!!!\n");
		}

		// Erroneous item
		else if(item != 5) 
			printf("You entered the wrong item!!!\n");
		printf("\n\n\n");

	} while (item != 5);

	free(ptr_data);

	return 0;
}
