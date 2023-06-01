#include <stdio.h>

#define M 10

int main(void)
{
	int square_matrix[M][M] = {0}, reverse_matrix[M] = {0}, triangular_matrix[M][M] = {0}, snail_matrix[M][M] = {0};
	int N = 0, i = 0, j = 0, k = 0, counter = 1, start_counter = 1, end_counter = 1;

	printf("1. Square matrix.\nEnter N (from 1 to 10) = ");
	
	do {
		scanf("%d",&N);
		if ((N<=0)||(N>10))
			printf("Enter N (from 1 to 10) = ");
	} while ((N<=0)||(N>10));

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			square_matrix[i][j] = counter;
			printf("%d ",square_matrix[i][j]);
			counter++;
		}
		printf("\n");
	}


	printf("\n\n2. Reverse matrix.\nEnter N (from 1 to 10) = ");
	do {
		scanf("%d",&N);
		if((N<=0)||(N>10))
			printf("Enter N (from 1 to 10) = ");
	} while ((N<=0)||(N>10));
	
	for(i = 0; i < N; i++){
		printf("Enter M[%d] = ",i);
		scanf("%d", &reverse_matrix[i]);
	}

	printf("Reverse matrix:");
	for(i = N-1; i >= 0; i--)
		printf("%d ",reverse_matrix[i]);

	
	printf("\n\n3. Triangular  matrix.\nEnter N (from 1 to 10) = ");

	do {
		scanf("%d",&N);
		if((N<=0)||(N>10))
		printf("Enter N (from 1 to 10) = ");
	} while ((N<=0)||(N>10));

	for(i = 0; i < N; i++) {
		for (j = 0; j < N; j++) { 
			triangular_matrix[i][j] = ((i+j)<N-1)?0:1;
			printf("%d ",triangular_matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n\n4. Snail matrix.\nEnter N (from 1 to 10) = ");
	
	do {
		scanf("%d",&N);
		if((N <= 0)||(N > 10))
			printf("Enter N (from 1 to 10) = ");
	} while ((N <= 0)||(N > 10));

	counter = 1;
	start_counter = 0;
	end_counter = N;

	k = N/2;


	while(k>0)
	{
		i = start_counter;
		j = start_counter;

		while(j < end_counter){
			snail_matrix[i][j] = counter;
			counter++;
			j++;
		}
		j--;
		i++;
		while(i < end_counter){
			snail_matrix[i][j] = counter;
			counter++;
			i++;
		}
		i--;
		j--;

		while(j >= start_counter){
			snail_matrix[i][j] = counter;
			counter++;
			j--;
		}
		j++;
		i--;

		while(i >= (start_counter + 1)){
			snail_matrix[i][j] = counter;
			counter++;
			i--;
		}
		start_counter++;
		end_counter--;
		k-=1;
	}

	if (N % 2)
		snail_matrix[N/2][N/2] = counter;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%2d ",snail_matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
