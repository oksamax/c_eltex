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
	int end_counter = 0, counter = 0, i = 0;
	char find_delete_firstname[20];

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
			else printf("Telephone directory is full!!!\n");
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
				scanf("%s",find_delete_firstname);
				for(i = 0; i < end_counter; i++) {
					if (!(strcmp(data[i].firstname, find_delete_firstname))) {
						printf("Firstname:%s Surname:%s Number:%s\n",data[i].firstname, data[i].surname, data[i].number);
						counter++;
					}
				}
				if (0 == counter) printf("User not found!\n");
				counter = 0;
			}
			else printf("Telephone directory is empty!!!\n");
		}

		// Delete user
		else if(4 == item){
			if (end_counter != 0){
				printf("Enter firstname:");
				scanf("%s",find_delete_firstname);
				for(i = 0; i < end_counter; i++){
					if(!(strcmp(data[i].firstname, find_delete_firstname))){
						printf("Delete user %s!\n",data[i].firstname);
						strcpy(data[i].firstname,data[end_counter-1].firstname);
						strcpy(data[i].surname,data[end_counter-1].surname);
						strcpy(data[i].number,data[end_counter-1].number);
						end_counter--;
						i--;
					}
				}
			}
			else printf("Telephone directory is empty!!!\n");
		}

		// Erroneous item
		else if(item != 5) 
			printf("You entered the wrong item!!!\n");
		printf("\n\n\n");

	} while (item != 5);

	return 0;
}
