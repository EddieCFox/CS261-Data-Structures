

struct dLink {

	TYPE value;
	struct dLink * next;
	struct dLink * prev;

};


struct linkedList {

	struct dLink * frontSentinel;
	struct dLink * backSentinel;
	int size;

};


int linkedListContains (struct linkedList *lst, TYPE e) {

	assert(!(LinkedListIsEmpty(lst)));

	dLink *temp = lst->frontSentinel;

	while (temp != backSentinel){
		if (EQ(temp->value, e))
			return 1;

		else
			temp = temp->next;
	}

	return 0;

}


void linkedListRemove (struct linkedList *lst, TYPE e) {

	assert(!(LinkedListIsEmpty(lst)));

	dLink *temp = lst->frontSentinel;

	while (temp != backSentinel)
 		if (EQ(temp->value, e))			
 			_removeLink(temp);

		else
			temp = temp->next;

}


void linkedListRemove(struct linkedList *lst, TYPE e)
{
    assert(!(LinkedListIsEmpty(lst)));

    dLink *temp = lst->frontSentinel;

    while (temp != backSentinel) {

        if (EQ(temp->value, e)) {
            _removeLink(lst, temp);
            break;
        }

        else {
            temp = temp->next;
        }
    }

    return 0;
}


What were the algorithmic complexities of the methods addLink and removeLink
that you wrote back in linked list for Deque?

	Answer: O(1)


Given your answer to the previous question, what are the algorithmic
complexities of the three principle Bag operations?

	Answer: Add -- O(1); 
			Contains -- Best O(1), Worst O(n);
			Remove -- Best O(1), Worst O(n)