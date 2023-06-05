#include <stdio.h>
#include <string.h>

struct str_data {
	char firstname[20];
	char surname[20];
	char number[20];
};

int main(void)
{
	struct str_data data[10];
	float item;
	int start_counter = 0, end_counter = 0, conuter = 0, i = 0;
	char find_firstname[20], delete_firstname[20];

	do {
		
		printf("***Telephone directory***\nMenu:\n1. Add user\n2. List of users\n3. Find user\n4. Delete user\n5. Exit\n\nEnter item:");
		scanf("%f",&item);

		//Add user
		if(1 == item) {
			if (end_counter != 10){
				printf("Enter firstname (from 1 to 20 characters): ");
				scanf("%s",data[end_counter].firstname);
				printf("Enter surname (from 1 to 20 characters): ");
				scanf("%s",data[end_counter].surname);
				printf("Enter number (from 1 to 20 characters): ");
				scanf("%s",data[end_counter].number);
				end_counter++;
			}
		}

		// List of users
		else if(2 == item) {
			if (end_counter != 0) {
				for(i = 0; i < end_counter; i++) {
					printf("%d. Firstname:%s  Surname:%s Number:%s\n",i+1,data[i].firstname, data[i].surname, data[i].number);
				}
			}
			else printf("Telephone directory is empty!!!\n");
		}

		// Find user
		else if(3 == item) {
			if (end_counter != 0) {
				printf("Enter firstname:");
				scanf("%s",find_firstname);
				for(i = 0; i < end_counter; i++) {
					if (!(strcmp(data[i].firstname, find_firstname))) {
						printf("Firstname:%s Surname:%s Number:%s\n",data[i].firstname, data[i].surname, data[i].number);
					}
				}
			}
			else printf("Telephone directory is empty!!!\n");
		}

		// Delete user
		else if(4 == item){

		}

		// Erroneous item
		else if(item != 5) 
			printf("You entered the wrong item!!!\n");
		printf("\n\n\n");

	} while (item != 5);

	return 0;
}
