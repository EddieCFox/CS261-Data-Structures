
Group 17 Worksheet 19
Date: 7/9/16



Question 3:
	
	Property for emptiness of a Linked List: frontSentinel->next = backSentinel, or backSentinel->prev = frontSentinel -- that is, the only elements in the list are the two sentinels.


Question 5:

	1. Allocate memory for a new link. 2. Set value of new link. 3. Set the previous field on the passed link argument to the newly added link. 4. Set the new link's next field to the passed link argument. 5. Set the new link's previous field to the link that was previously before the argument 6. Adjust next field of previous link to new link


Question 6:

	Because the sentinels are present, _removeLink() can be abstracted to the general case of any extant link in the list, because there will always be two links on either side of the link being removed. The most important thing to remember with this is that it should be impossible to remove the sentinels themselves.


Question 7:

	add() and remove() both execute in constant time, O(1)




/* write addLink and removeLink. Make sure they update the size field correctly */
/* _addBefore places a new link BEFORE the provide link, lnk */

void _addBefore (struct linkedList *q, struct dlink *lnk, TYPE e) {
	struct dlink *newLink = malloc(sizeof(struct dlink));
	assert(newLink); // make sure memory was allocated successfully

	newLink->value = e;
	newLink->next = lnk; //newLink placed before lnk provided as argument
	newLink->prev = lnk->prev;
	newLink->prev->next = newLink;
	
	lnk->prev = newLink;
	q->size++; //increment size
}


void _removeLink (struct linkedList *q, struct dlink *lnk) {

	assert(!LinkedLIstIsEmpty(q)); //make sure we have something to work with
	assert(dlink != q->frontSentinel && dlink != q->backSentinel)
	struct dlink *temp = lnk; //for mem mgmt. later
	
	lnk->prev->next = lnk->next; //handle prev link
	lnk->next->prev = lkn->prev; //handle next link
	
	free(temp); //release memory
	temp = 0;
	q->size--; //decrement size

}


TYPE LinkedListFront (struct linkedList *q) {
	assert(!LinkedListIsEmpty(q)); //make sure we have something to work with
	return q->frontSentinel->next->value;
}
 
TYPE LinkedListBack (struct linkedList *q) {
	assert(!LinkedListIsEmpty(q)); //make sure we have something to work with
	return q->backSentinel->prev->value;
}

