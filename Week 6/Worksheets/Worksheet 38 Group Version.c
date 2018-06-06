void initHashTable(struct hashTable * ht, int size) 
{	
	int i;
	assert(size > 0);
	assert(ht != 0);
	
	ht->table = (struct hlink*)malloc(size * sizeof(struct hlink*));
	ht->tablesize = size;
	ht->count = 0;

	for (i = 0; i < ht->tablesize; i++)
	{
		ht->table[i]->value = 0;
		ht->table[i]->next = 0;
	}

}

int hashTableContains(struct hashTable * ht, TYPE testElement) {

	int hashIndex;
	hashIndex = HASH(testElement) % ht->tablesize;
	if (hashIndex < 0) hashIndex += ht->tablesize;

	struct hlink *temp = ht->table[hashIndex];
	while (temp != 0) {
		if (temp->value == testElement) {
			return 1;
		}
		else {
			temp = temp->next;
		}
	}

	return 0;

}

void hashTableRemove(struct hashTable * ht, TYPE testElement) {
	int hashIndex;
	struct link *temp;
	struct link *prev;

	assert(ht->tablesize > 0);

	hashIndex = HASH(testElement) % ht->tablesize;
	if (hashIndex < 0) hashIndex += ht->tablesize;

	temp = ht->table[hashIndex];
	while (temp != 0 || temp->value != testElement) {
		prev = temp;
		temp = temp->next;
	}

	if (temp->value == testElement) {
		prev->next = temp->next;
		ht->count--;
		free(temp)
	}
}

void resizeTable(struct hashTable *ht) {

	int i = 0;

	struct openHashTable *newTable;
	struct openHashTable *temp;

	initHashTable(newTable, ht->tablesize * 2);

	while (i < ht->tablesize) {
		temp = ht->table[i];
		while (temp != 0) {
			hashTableAdd(newTable, temp->value);
			temp = temp->next;
		}
		i++;
	}

	temp = ht;
	ht = newTable;
	free(temp);
}