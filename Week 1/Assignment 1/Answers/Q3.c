/* CS261- Assignment 1 - Q.3*/
/* Name: Eddie C. Fox
 * Date: July 3, 2016
 * Solution description: This program generates an array of 20 random numbers, prints it,
 sorts the array, and then prints the newly sorted array.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/     
	
	int i;
	int j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (number[j] > number[j + 1])
			{
				
				int temp = number[j + 1];
				number[j + 1] = number[j];
				number[j] = temp;
			}
		}
	}

}

int main(){
    /*Declare an integer n and assign it a value of 20.*/

	int n = 20;
	int i;
    
    /*Allocate memory for an array of n integers using malloc.*/

	int* arrayOfIntegers = malloc(20 * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/

	for (i = 0; i < 20; i++)
	{
		arrayOfIntegers[i] = rand();
	}
    
    /*Print the contents of the array.*/

	printf("Unsorted array:\n");
	
	for (i = 0; i < 20; i++)
	{
		printf("%d\n", arrayOfIntegers[i]);
	}

	printf("\n");

	/*Pass this array along with n to the sort() function of part a.*/

	sort(arrayOfIntegers, n);

	/*Print the contents of the array.*/

	printf("Sorted Array:\n");

	for (i = 0; i < 20; i++)
	{
		printf("%d\n", arrayOfIntegers[i]);
	}

	free(arrayOfIntegers);
	arrayOfIntegers = 0;

    return 0;
}
