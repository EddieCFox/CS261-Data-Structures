/* CS261- Assignment 1 - Q.1*/
/* Name: Eddie C. Fox
 * Date: July 3, 2016
 * Solution description: This function provides functions for the creation and usage 
 of a student structure designed to deal with 10 students, their id's, and their scores.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     
	struct student *studentsPtr = malloc(10 * (sizeof(struct student)));

     /*return the pointer*/

	return studentsPtr;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     
	int i;
	int j;
	int x;
	int y;
	int used; /* This variable is 1 if the ID value has already been used, and 0 if the ID value hasn't been used yet. */

	for (i = 0; i < 10; i++)
	{
		do
		{
			used = 0;
			x = (rand() % 10) + 1;

			for (j = 0; j < 10; j++)
			{
				if (students[j].id == x)
				{
					used = 1;
					break;
				}

			}
		} while (used == 1);


		y = (rand() % 100);

		students[i].id = x;
		students[i].score = y;
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

	int min = 100;
	int max = 0;

	double total = 0;
	double average = 0;

	int i;

	for (i = 0; i < 10; i++)
	{
		if (min > students[i].score)
		{
			min = students[i].score;
		}

		if (max < students[i].score)
		{
			max = students[i].score;
		}

		total += (students[i].score);

	}

	average = (total / 10);

	printf("Minimum Score: %d\n", min);
	printf("Maximum Score: %d\n", max);
	printf("Average Score: %g\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

	if (stud != NULL)
	{
		free(stud);
		stud = 0;
	}
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    
	stud = allocate();

    /*call generate*/

	generate(stud);
    
    /*call output*/

	output(stud);
    
    /*call summary*/

	summary(stud);
    
    /*call deallocate*/

	deallocate(stud);

    return 0;
}
