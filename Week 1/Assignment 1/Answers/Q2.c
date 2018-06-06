/* CS261- Assignment 1 - Q.2*/
/* Name: Eddie C. Fox
 * Date: July 3, 2016
 * Solution description: This program manipulates 3 values, 2 of which are passed by 
 reference in order to practice pointer and address manipulation.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/

	*a *= 2;
    
    /*Set b to half its original value*/
    
	*b /= 2;

    /*Assign a+b to c*/
    
	c = *a + *b;

    /*Return c*/

	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/

	int x = 5;
	int y = 6;
	int z = 7;
	int return_value;
    
    /*Print the values of x, y and z*/

	printf("X: %d\nY: %d\nZ: %d\n\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/

	return_value = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    
	printf("%d\n\n", return_value);

    /*Print the values of x, y and z again*/

	printf("X: %d\nY: %d\nZ: %d\n", x, y, z);
 
    /*Is the return value different than the value of z?  Why?*/

    return 0;
}

/* Yes, there is a difference between the return value and the value of Z. X and Y were passed into Foo by reference, because the parameter
list for foo called for addresses of a and b to be passed in. C, on the other hand, was passed by value. Because of this, only a copy of the value
of Z at the time foo was called was passed in, as opposed to an address, as in the cases of X and Y. While X and Y remain modified after the foo call,
modifications to Z were only local due to the passing by value. When Z is assigned the value of 13 in the foo function and returned, this modification is not saved,
as it is only done to a copy of Z. Therefore the value of Z, printed after the foo function will be identical to the value of Z before foo was called. */