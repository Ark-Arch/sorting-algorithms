/* Expecting that the array elements are integer values */

#include <stdio.h>
#include <stdlib.h>

void prn_instructions(void);
int *  ascend_sort(int params[], int size);
int *  descend_sort(int params[], int size);
void   results(int params[], int size);

int main (void) 
{
	int           mode, sum = 0;
	float         mean, median;
	int           array_size;
	char          order;
	int           *sorted_array;

	prn_instructions();

	// ASK FOR THE NUMBER OF ARRAY ELEMENTS INTENDED FOR SORTING
	printf("\n Please determine what count of numbers you intend to input: \n");
	printf(">> ");
	scanf("%d", &array_size);

	// ASK FOR THE ARRAY ELEMENTS
	printf("\n\n Please input %d numbers >>  ", array_size);
	int          array[array_size];
	for (int i = 0; i < array_size; ++i) {
		scanf("%d", &array[i]);		
	}

	// CONFIRM IN WHAT ORDER IT IS NEEDED TO BE SORTED
	printf("\nIn what order do you want your array sorted ('a' for ascending, 'd' for descending)>> ");
	scanf(" %c", &order);

	if (order == 'a') {
		printf("\nYou have chosen the ascending order.");
		sorted_array = ascend_sort(array, array_size);
		}
	else if (order == 'd') {
		printf("\nYou have chosen the descending order.");
		sorted_array = descend_sort(array, array_size);
		}
	else {
		printf("\nSorry you have not provided with an available choice.\n");
		exit(1);
		}

	results(sorted_array, array_size);	

	return 0;
}

void prn_instructions(void){
	printf("\nWelcome dear user!. Please take note of the following instructions:\n");
	printf("\n1. the array expected is supposed to be of the type int");
	printf("\n2. you are allowed to determine the size of the array");
	printf("\n3. please ensure that the size of array is a positive integer number\n\n");
}


int * ascend_sort(int params[], int size){
	int i, j, tmp;
	
	for (i=0; i < size - 1; i++){
		for(j = 0; j < size - i - 1; j++){
			if (params[j] > params[j+1]){
				tmp = params[j];
				params[j] = params[j+1];
				params[j+1] = tmp;
			}
		}
	}
	
	return params;
}

int * descend_sort(int params[], int size){
	int i, j, tmp;

	for (i=0; i<size; ++i){
		for(j = size - 1; j > i; --j){
		       if (params[j-1] < params[j]) {
		       		tmp = params[j-1];
				params[j-1] = params[j];
				params[j] = tmp;
		       }
		}
	}

	return params;	
}

void results(int params[], int size){
	int   sum = 0, mode, median;
	float mean;
	
	printf("\nThis are the numbers in the requested sort >> \n");
	for (int i = 0; i< size; ++i){
		printf("%d ",params[i]);
		sum += params[i];}

	mean = (double) sum/ size;
	printf("\nThis is the average of the scores >> %f\n", mean);

	if (size % 2 == 0) {
		median = (size/2);
		printf("The median number of the array is >> %d\n", (params[median-1] + params[median])/2);
	}
	else{
		median = (size/2);
		printf("The median number of the array is >> %d\n", params[median]);
	}
}


