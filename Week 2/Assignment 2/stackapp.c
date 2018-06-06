/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"

/* This function is a bit off, but I wanted to get something in before the 24 hour deadline.*/


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	struct DynArr *stack = newDynArr(8); /* Allocate stack structure, and set initial capacity to 8.*/
	char character; /* Set character variable to hold characters of string one at a time.*/

	while ((character = nextChar(s)) != 0) /* While there is a next character to read. While loop terminates if NULL, or nothing is next.*/
	{
		switch (character) /* I'm using a switch statement with character here because switch allows me to cover several 
						   cases with the same outcome at once, before I put a break statement.*/
		{
		case '(':
		case '{':
		case '[':
			pushDynArr(stack, character); /* If the character is (, {, or [, push it onto the stack. These are the opening parantheses and such. */

		case ')':
			if (topDynArr(stack) == '(') /* If there was a ( before the ), take the ( off the stack and break, reading the next character.*/
			{
				popDynArr(stack);
				break;
			}

			else /* If else is triggered, the stack is imbalanced. We delete the stack structure before returning 0. */
			{
				deleteDynArr(stack);
				return 0;
			}

		case '}':
			if (topDynArr(stack) == '{') /* If there was a { before the }, take the { off the stack and break, reading the next character.*/
			{
				popDynArr(stack);
				break;
			}

			else /* If else is triggered, the stack is imbalanced. We delete the stack structure before returning 0. */
			{
				deleteDynArr(stack);
				return 0;
			}

		case ']':
			if (topDynArr(stack) == '[') /* If there was a [ before the ], take the [ off the stack and break, reading the next character.*/
			{
				popDynArr(stack);
				break;
			}

			else /* If else is triggered, the stack is imbalanced. We delete the stack structure before returning 0. */
			{
				deleteDynArr(stack);
				return 0;
			}
		}
	}

	/* We are not done after the while loop. Even if the function hasn't returned 0, there could be numerous ((((, which might only
	be balanced by an insufficent amount of ). Therefore, we need to check if the stack still has values after execution.*/

	if (sizeDynArr(stack) != 0) /* If there is still characters on the stack after the while loop, the string is imbalanced. */
	{
		return 0;
	}

	/* At this point, if 0 hasn't been returned by the function, the string is balanced, so we can return 1 after deelting the array. */
	deleteDynArr(stack); 

	return 1;

}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");
	s = "";

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

