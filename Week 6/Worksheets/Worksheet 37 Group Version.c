void openHashTableAdd(struct openHashTable * ht, TYPE *newValue) {
	int idx;
	/* Make sure we have space and under the load factor threshold*/
	if ((ht->count / (double)ht->tablesize) > 0.75)
		_resizeOpenHashTable(ht);
	ht->count++; //increment for addition
	idx = HASH(newValue) % ht->tablesize;
	/* To be safe, use only positive arithmetic. % may behave very differently on diff implementations or diff languages . However, you can do the following to deal with a negative result from HASH */
	if (idx < 0)
		idx += ht->tablesize;

	//start of our implementation
	while (ht->table[idx] != 0) {
		idx++;
		if (idx >= ht->tablesize)
			idx = 0; //set equal to 0th index
	}
	ht->table[idx] == newValue; //if we get here we found the desired location
}

int openHashTableBagContains(struct openHashTable *ht, TYPE newValue) {
	int idx;
	idx = HASH(newValue) % ht->tablesize;
	if (idx < 0)
		idx += ht->tablesize;

	//start of our implementation
	while (ht->table[idx] != 0) { //if we reach a null we've went too far
		if (*(ht->table[idx]) == newValue)
			return 1; //found
		idx++;
		if (idx >= ht->tablesize)
			idx = 0; //set equal to 0th index
	}
	return 0; //was not found
}

void _resizeOpenHashTable(struct openHashTable *ht) {

	int i = 0;

	struct openHashTable *newTable;
	struct openHashTable *temp;

	initOpenHashTable(newTable, ht->tablesize * 2);

	while (i < ht->tablesize) {
		openHashTableAdd(newTable, ht->table[i]);
		i++;
	}

	temp = ht;
	ht = newTable;
	free(temp);

}
