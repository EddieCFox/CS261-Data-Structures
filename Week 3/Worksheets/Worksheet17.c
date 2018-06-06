
Group 17 Worksheet 17
Date: 7/9/16



void linkedListStackPush (struct linkedListStack *s, TYPE d) {

	struct link *newLink = (struct link *) malloc(sizeof(struct link));
	assert (newLink != 0);

	newLink->value = d;


	if (!linkedListStackIsEmpty(s))
		newLink->next = 0;

	else
		newLink->next = s->firstLink;


	s->firstlnk = newLink;
}



TYPE linkedListStackTop (struct linkedListStack *s) {

	assert(!linkedListStackIsEmpty(s));
	return s->firstlink->value;

}


void linkedListStackPop(struct linkedListStack *s) {

	assert(!linkedListStackIsEmpty(s));
	
	struct link *temp = s->firstLink;
	s->firstLink = temp->next;
	
	free(temp);
	temp = 0;

}

int linkedListStackIsEmpty (struct linkedListStack *s) {

	return (s->firstLink == 0);

}