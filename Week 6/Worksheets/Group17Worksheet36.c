/****************************************************
** Authors: Lok I Chan, Eddie Fox, Tanner England, Catherine Smith, Trevor Worthey
** Date: 7/26/16
** Description - Worksheet 36 Group 17
****************************************************/

Algorithmic execution time for each operation:
int  containsKey (KEYTYPE key) 		  |	- O(n)
void get(KEYTYPE key, VALUETYPE *ptr) | - O(n)
void put(KEYTYPE key, VALUETYPE value)| - O(n)
void remove (KEYTYPE key)   		  |	- O(n)

#include <stdio.h>

void dyArrayDictionaryGet (struct dynArr *da, KEYTYPE key, VALUETYPE* valptr) {
	assert(da);//make sure array isn't null
    int i;
    for (i = 0; i < da->size; i++) {
        if (compare(da->data[i]->key, key) == 0) {
            *valptr = da->data[i]->value;
        }
    }
}

int dyArrayDictionaryContainsKey (struct dynArray *da, KEYTYPE key) {
    assert(da); //make sure array isn't null
	assert(da->size); //make sure array isn't empty
    int i;
    for (i = 0; i < da->size; i++) {
        if (compare(da->data[i]->key, key) == 0) {
            return 1;
        }
    }
    //else it was not found
    return 0;
}

void dyArrayDictionaryRemove (struct dynArray *da, KEYTYPE key) {
	assert(da); //make sure array isn't null
	assert(da->size);//make sure array isn't empty
    struct association *temp;
	int i;
    for (i = 0; i < da->size; i++) {        
        if(compare(da->data[i]->key, key) == 0) {
            temp = da->data[i];
            removeAtDynArr(da, i);
            free(temp);
        }
    }
}
//given to us
void dyArrayDictionaryPut (struct dynArray *da, KEYTYPE key, VALUETYPE val) {
	struct association * ap;
	if (dyArrayDictionaryContainsKey(da, key))
		dyArrayDictionaryRemove(da, key);
	ap = (struct association *) malloc(sizeof(struct association));
	assert(ap != 0);        
	ap->key = key;        
	ap->value = val;        
	dyArrayAdd(da, ap);
}