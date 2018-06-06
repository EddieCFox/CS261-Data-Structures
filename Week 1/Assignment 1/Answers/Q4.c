/* CS261- Assignment 1 - Q.4*/
/* Name: Eddie C. Fox
 * Date: July 3, 2016
 * Solution description: This program combines Q1 and Q3, utilizing the sorting function 
 of Q3 with the general structures and functions of Q1. 
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     

	int i;
	int j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (students[j].score > students[j + 1].score)
			{

				int temp = students[j + 1].score;
				students[j + 1].score = students[j].score;
				students[j].score = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
    
	int n = 10;
	int i;
	int j;
	int x;
	int y;
	int used;

    /*Allocate memory for n students using malloc.*/

	struct student *studentsPtr = malloc(10 * (sizeof(struct student)));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/

	for (i = 0; i < 10; i++)
	{
		do
		{
			used = 0;
			x = (rand() % 10) + 1;

			for (j = 0; j < 10; j++)
			{
				if (studentsPtr[j].id == x)
				{
					used = 1;
					break;
				}

			}
		} while (used == 1);


		y = (rand() % 100);

		studentsPtr[i].id = x;
		studentsPtr[i].score = y;
	}
    
	/*Print the contents of the array of n students.*/

	printf("Unsorted:\n");

	for (i = 0; i < 10; i++)
	{
		printf("%d %d\n", studentsPtr[i].id, studentsPtr[i].score);
	}

	/*Pass this array along with n to the sort() function*/

	sort(studentsPtr, n);

	/*Print the contents of the array of n students.*/

	printf("\nSorted:\n");

	for (i = 0; i < 10; i++)
	{
		printf("%d %d\n", studentsPtr[i].id, studentsPtr[i].score);
	}
    
    return 0;
}
