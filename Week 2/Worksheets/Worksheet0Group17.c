

--- GROUP 17 WORKSHEET 0 ---
--- Date: 7.2.16 ---


Worksheet 0: Building a Simple ADT Using an Array
In Preparation: Read about basic ADTs. 

In this worksheet we will construct a simple BAG and STACK abstraction on top of an
array. Assume we have the following interface file (arrayBagStack.h) :


# ifndef ArrayBagStack
# define ArrayBagStack

# define TYPE int
# define EQ(a, b) (a == b)

#include <assert.h> //?? can we add to this section?

struct arrayBagStack {
TYPE data [100];
int count;
};

void initArray(struct arrayBagStack * b);
void addArray (struct arrayBagStack * b, TYPE v);
int containsArray (struct arrayBagStack * b, TYPE v);
void removeArray (struct arrayBagStack * b, TYPE v);
int sizeArray (struct arrayBagStack * b);

void pushArray (struct arrayBagStack * b, TYPE v);
TYPE topArray (struct arrayBagStack * b);
TYPE popArray (struct arrayBagStack * b);
int isEmptyArray (struct arrayBagStack * b);
# endif



Your job, for this worksheet, is to provide implementations for all these operations.


void initArray (struct arrayBagStack * b){
	//b = malloc(sizeof(struct arrayBayStack)); //??
	b->count = 0; // count to 0
}

/* Bag Interface Functions */

void addArray (struct arrayBagStack * b, TYPE v) {
	if(b->count < 100) {
		b->data[b->count] = v; //set value at appropriate array index
		b->count++; //increment count for next entry / index
	}
	//else increase size dynamically?
}

//assuming this is a simple search function
int containsArray (struct arrayBagStack * b, TYPE v){
	//run through array to compare v to indexed value, return 1 if found
	for(int i = 0 ; i < b->count; i++) {
		if(EQ(b->data[i], v)))
			return 1;
	}
	//if we get here no match was found
	return 0;
}

void removeArray (struct arrayBagStack * b, TYPE v) {
	assert(containsArray(b, v)); //verify v is in bag
	for(i = 0; i < b->count; i++) { //run through each array value to see if it is equal to v
		if(EQ(b->data[i], v)) { //if equal, remove by reindexing all subsequent array values by 1
			for(j = i; j < b->count - 1; j++) {
				b->data[j] = b->data[j + 1];
			}
			b->count--;
		}
	}	
}

int sizeArray (struct arrayBagStack * b) {
	return b->count;
}


/* Stack Interface  Functions */

void pushArray (struct arrayBagStack * b, TYPE v) {
	if(b->count < 100) {
		b->data[b->count] = v;
		b->count++;
	}
}

TYPE topArray (struct arrayBagStack * b) {
	assert(b->count > 0);
	return b->data[b->count -1];
}

TYPE popArray (struct arrayBagStack * b) {
	TYPE temp = topArray(b);
	if(b->count > 0) {
		b->data[b->count] = 0;
		b->count--;
	}
	return temp;
}


int isEmptyArray (struct arrayBagStack * b) {
	return (!(b->count)); //if count is anything other than 0, bool will be 1 (although it's not a bool, evaluates that way)
}

