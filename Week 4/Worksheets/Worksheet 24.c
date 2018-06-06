//worksheet 24

struct linkedListIterator {
	struct linkedList * lst;
	struct dLink * currentLink;
}


/* We decided to change currentLinks initialization from lst->frontSentinel->next to lst->frontSentinel.
The reasoning is as follows: If there's nothing besides an empty list, frontSentinel->next already starts at the back sentinel, 
so then the next value would be NULL, and would fulfill the test of not equaling back sentinel. Conceptually, the back sentinel
is supposed to represent the end of the function, so we shouldn't think of it having a next value, and the function should return 
false. By making frontSentinel the initial current Value, the function would quickly stop in an empty linkedlist and return false as 
expected, because next would be the back sentinel. */

void linkedListIteratorInit (struct linkedList *lst, struct linkedListIterator * itr) {
	itr->lst = lst;
	itr->currentLink = lst->frontSentinel;
}

void _removeLink (struct linkedList *lst, struct dLink * lnk);


int linkedListIteratorHasNext (struct linkedListIterator *itr) {
	assert(itr);
	if (itr->currentLink->next != itr->lst->backSentinel) 
	{
		return 1;
	} 
	
	else 
	{
		return 0;
	}
}

TYPE linkedListIteratorNext (struct linkedListIterator *itr) {
	assert(linkedListIteratorHasNext(itr));
	itr->currentLink = itr->currentLink->next;
	return itr->currentLink->value;
	
}

/* think about the next one carefully. Draw a picture. 
 What should itr->currentLink be pointing to after the remove operation ? */

/* itr->currentLink points to the node immediately before the one being removed. */

void linkedListIteratorRemove (struct linkedListIterator *itr) {
	struct dLink* temp = itr->currentLink;
	itr->currentLink = itr->currentLink->prev;
	_removeLink(itr->lst, temp);
}