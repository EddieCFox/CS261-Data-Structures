
--- GROUP 17 WORKSHEET 21 ---
Date: 7.2.16


void _setCapacityDynArr(struct DynArr *v, int newCap) {
	
	TYPE temp*;
	temp = malloc(sizeof(TYPE) * newCap);

	for (int i = 0; i < v->size; i++) {
		temp[i] = v->data[i];
	}

	free(v->data);

	v->data = temp;
	v->capacity = newCap;

}


TYPE getDynArr (struct DynArr * da, int position) {

	assert(position < size && position > -1);

	return da->data[position];


}


void putDynArr(struct DynArr * da, int position, TYPE value) {

	assert(position < size && position > -1);

	da->data[position] = value;

}


void swapDynArr (struct DynArr * da, int i, int j) {

	assert(i < size && i > -1);
	assert(j < size && j > -1);

	TYPE temp;
	
	temp = getDynArr( da , i);
	
	putDynArr( da , i ,  j);
	putDynArr(da , j , temp);

}


void removeAtDynArr (struct DynArr * da, int index) {

	assert(index < size && index > -1);

	for(int i = index; i < da->size; i++)
		
		da->data[i] = da->data[i + 1];

	da->data[da->size] = 0;
	da->size--;

}