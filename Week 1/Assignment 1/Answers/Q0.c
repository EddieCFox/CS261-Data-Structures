/* CS261- Assignment 1 - Q. 0*/
/* Name: Eddie C. Fox
 * Date: July 3, 2016
 * Solution description: First, x is declared an integer value in main.
 The address of X is then printed. Then fooA is called, being passed the
 address of x. It dereferences the address, printing the value of X, then
 prints the address of X, and finally prints the address of the pointer itself.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/

	printf("%d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
     
	printf("%d\n", iptr);

     /*Print the address of iptr itself*/

	printf("%p\n", &iptr);

}

int main(){
    
    /*declare an integer x*/

	int x = 7;
    
    /*print the address of x*/
    
	printf("%d\n", &x);

    /*Call fooA() with the address of x*/
    
	fooA(&x);
    /*print the value of x*/

	printf("%d\n", x);
    
    return 0;
}
