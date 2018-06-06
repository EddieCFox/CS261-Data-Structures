
--- GROUP 17 WORKSHEET 21 ---
Date: 7.2.16


int containsDynArr (struct DynArr * da, TYPE e) {

	int a;

	for(a=0;a<da->size;a++) {

		if(EQ(e,da->data[i]))
			return 1;
	}
		return 0;
}


1. What should the removeAt method do if the index given as argument is not in range?

	Answer: The function should contain an assert() statement checking the index against the bounds of the array, terminating program execution if true.


2. What is the algorithmic complexity of the method removeAt? Given your answer to the previous question, what is the worst-case complexity of the method remove?

	Answer: The worst case of this function (assuming no error) is if the element to be deleted is in first position. However, this simply increases number of time steps, while leaving complexity unchanged as: O(n).


3. What are the algorithmic complexities of the operations add and contains?

	Answer:

	Add() -- Best case is O(1), worst case is O(n)
	Contains -- Best case is O(1), worst case is O(n)