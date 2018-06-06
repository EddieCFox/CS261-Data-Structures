
--- GROUP 17 WORKSHEET 16 ---
--- Date: 7.2.16 ---



# define TYPE int
struct DynArr {
	TYPE *data;
	int size;
	int capacity;


};

/* Dynamic Array implementation of the Stack Interface */
void pushDynArray (struct DynArr * da, TYPE e) {

	addDynArr(da, e);

}
 
TYPE topDynArray (struct DynArr * da) {
	
	assert(da->size > 0);
	return getDynArr(da, da->size - 1);

}

void popDynArray (struct DynArr * da) {

	assert(da->size > 0);
	removeAtDynArr(da, da->size - 1);


}

int isEmptyDynArray (struct DynArr * da) {

	return !(da->size)
}


1. What is the algorithmic execution time for the operations pop and top?

	Answer: O(1)

2. What is the algorithmic execution time for the operation push, assuming there is sufficient capacity for the new elements?

	Answer: O(1)

3. What is the algorithmic execution time for the internal method _setCapacityDynArr?

	Answer: O(n)


4. Using as a basis your answer to 3, what is the algorithmic execution time for the operation push assuming that a new array must be created.

	Answer: O(n)