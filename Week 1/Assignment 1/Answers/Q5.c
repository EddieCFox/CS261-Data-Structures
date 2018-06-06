/* CS261- Assignment 1 - Q.5*/
/* Name: Eddie C. Fox
 * Date: July 3, 2016
 * Solution description: This program prompts the user to enter a word. The program prints
 the word altered in such a way that caps alternate, starting with upper case for the first letter. 
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/

	int length = strlen(word);
	int i;

	for (i = 0; i < length; i++)
	{
		if ((i % 2) == 0) /* Even lengthed character */
		{
			if (word[i] >= 'a' && word[i] <= 'z') /* If character is lower cased. ASCII code between 97 and 122. */
			{
				word[i] = toUpperCase(word[i]); /* Convert character from lower case to Upper case. */
			}
			
		}

		else /* Odd lengthed charachter */
		{
			if (word[i] >= 'A' && word[i] <= 'Z') /* If charachter is upper cased. ASCII code between 65 and 90. */
			{
				word[i] = toLowerCase(word[i]); /* Convert character from Upper case to lower case.*/
			}
		}
	}
}

int main(){
    /*Read word from the keyboard using scanf*/

	char word[100];

	printf("Please enter a word.\n");
	scanf("%s", word);
    
    /*Call sticky*/

	sticky(word);
    
    /*Print the new word*/

	printf("%s\n", word);
    
    return 0;
}
