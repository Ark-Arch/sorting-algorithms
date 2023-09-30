/* Expecting that the array elements are integer values */

#include <stdio.h>

void prn_instructions(void);

int main (void) 
{
	int           i, j, mode, tmp, sum = 0;
	float         mean, median;
	int           array_size;

	prn_instructions();

	// ASK FOR THE NUMBER OF ARRAY ELEMENTS INTENDED FOR SORTING
	printf("\n Please determine what count of numbers you intend to input: \n");
	printf(">> ");
	scanf("%d", &array_size);


	return 0;
}

void prn_instructions(void){
	printf("\nWelcome dear user!. Please take note of the following instructions:\n");
	printf("\n1. the array expected is supposed to be of the type int");
	printf("\n2. you are allowed to determine the size of the array");
	printf("\n3. please ensure that the size of array is a positive integer number\n\n");
}

