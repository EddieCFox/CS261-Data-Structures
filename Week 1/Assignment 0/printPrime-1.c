/************************
** Author: Eddie C. Fox
** Date: June 27, 2016
** Description: This program prints out integer prime numbers in an infinte loop until the 
** user stops executing the code.
***********************/

#include <stdio.h>


int isPrime(int n);

int main(void)
{
	
	char next = '\n';
	int n = 2;

	printf("This program lists the next prine number with each press of enter.\n");
	printf("To stop the program, type anything and press enter.\n");
	printf("To see another prime number, press enter.\n\n");

	while (next == '\n')
	{
	
		if (isPrime(n) == 1)
		{
			printf("%d\n", n);
			next = getchar();
		}

		n++;
	}

	return 0;
}

/*************************
**                                    int isPrime(int n)
** Description: Returns 1 if the number is a prime and 0 if a number isn't prime.
** The psudeocode for determining testing prime numbers was inherited from wikipedia.
** https://en.wikipedia.org/wiki/Primality_test , under the psudeocode section for simple methods.
** Because C doesn't seem to have a built in boolean type, I decide to just make
** an integer function that returns 1 for true and 0 for false, and is then used with the main function.
*************************/

int isPrime(int n)
{
	if (n == 2)
	{
		return 1;
	}

	if (n == 3)
	{
		return 1;
	}

	if (n % 2 == 0)
	{
		return 0;
	}

	if (n % 3 == 0)
	{
		return 0;
	}

	int i = 5;

	while (i * i <= n)
	{
		if ((n % i == 0) || (n % (i + 2) == 0))
		{
			return 0;
		}
		
		i += 6;
	}

	return 1;
}