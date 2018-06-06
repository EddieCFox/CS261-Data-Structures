
Group 17 Worksheet 18
Date: 7/9/16


void listQueueAddBack (struct listQueue *q, TYPE e) {

	struct link *newLink = malloc(sizeof(struct link));
	
	assert(newLink);
	
	newLink->value = e;
	newLink->next = 0;
	
	q->lastLink->next = newLink; //lastLink in queue points to newLink
	q->lastLink = newLink; //newLink now last in queue

}


TYPE listQueueFront (struct listQueue *q) {

	assert(!listQueueIsEmpty(q));
	return q->firstLink->next->value;

}


void listQueueRemoveFront (struct listQueue *q) {

	void listQueueRemoveFront (struct listQueue *q) {
	
		assert(!listQueueIsEmpty(q));
		struct link *temp = q->firstLink->next;

		if(!temp->next) //only one in queue
			q->lastLink = q->firstLink;


		q->firstLink->next = temp->next;
	
		free(temp);
		temp = 0;
	}
}


/* Fully commented version of above:

void listQueueRemoveFront (struct listQueue *q) {
	
	assert(!(listQueueIsEmpty(q))); 
	// check to see if there are any links besides the sentinel. If execution continues, there is at least one real link.
	
	struct link *temp = q->firstlink->next; 
	// set temp equal to the first real link.
	
	q->firstlink->next = temp->next; 
	// Point the sentinel's next link to the first real link that isn't being deleted.
	// Will set sentinels next to 0 if there is only one real link.

	if (!(temp->next)) // Condition will be fulfilled if there is only one real link left in the queue.b
	{
		q->lastLink = q->firstlink; // adjust lastlink pointer back to the sentinel, which also indicates queue is empty (beside sentinel)
	}
	
	free(temp); // delete temp, which is pointing to the first real link.
	temp = 0; // set temp to 0 to prevent dangling pointer issues.
}

*/



int listQueueIsEmpty (struct listQueue *q) {

	return (q->firstLink == q->lastLink);

}