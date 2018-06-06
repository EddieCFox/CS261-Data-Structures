//worksheet 23

void dynArrayRemoveAt (struct dynArray * da, int index);

struct dynArrayIterator {
	struct dynArray * da;
	int currentIndex;
};

void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
	assert(da);
	itr->da = da;
	itr->currentIndex = 0;
	
}

int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {
	assert(itr);
	assert(itr->currentIndex >= 0);
	if (itr->currentIndex + 1 < itr->da->size) {
		return 1;
	}else {
		return 0;
	}
}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {
	assert(dynArrayIteratorHasNext(itr));
	itr->currentIndex = itr->currentIndex++;
	return itr->da->data[itr->currentIndex];
}

void dynArrayIteratorRemove (struct dynArrayIterator *itr) {
	assert(itr);
	assert(itr->currentIndex >= 0);
	dynArrayRemoveAt(itr->da, itr->currentIndex);
	itr->currentIndex--;
}