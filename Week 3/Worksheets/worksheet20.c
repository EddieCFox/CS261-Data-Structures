
Group 17 Worksheet 22
Date: 7/9/16


void dequeAddFront (struct deque *d, TYPE newValue) {

	if (d->size >= d->capacity) 
		_dequeSetCapacity(d, 2*d->capacity);

	if (d->beg) {
		
		d->beg--;
		d->size++;
		d->data[d->beg]=newValue;
	}

	else {

		d->beg = d->capacity-1;
		d->size++;
		d->data[d->beg] = newValue;
	}
}


void dequeAddBack (struct deque *d, TYPE newValue) {

	int index = d->beg + d->size;
	
	if (d->size >= d->capacity) 
		_dequeSetcapacity(d, 2* d->capacity);

	if (index > d->capacity)
		d->data[index - d->capacity];

	else
		d->data[index] = newValue;

	d->size++;
}


TYPE dequeFront (struct deque *d) {

	assert(d->size);
	return d->data[d->beg];

}


TYPE dequeBack(struct deque * d) {

	int index = d->beg + d->size - 1;

	if (index > d->capacity)
		index -= d->capacity;
	
	return d->data[index];

}


void dequeRemoveFront (struct deque *d) {
	
	assert(d->size);
	
	if (d->beg == d->capacity - 1)
		d->beg = 0;

	else
		d->beg = d->beg + 1;

	d->size--;

}


void dequeRemoveBack (struct deque *d) {
	
	assert(d->size);
	d->size--;

}