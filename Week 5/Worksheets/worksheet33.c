GROUP 17 WORKSHEET 33
Date: 7.23.16


void _adjustHeap(struct dyArray *heap, int max, int pos)
{
	int leftChild = 2 * pos + 1; 
	int rightChild = 2 * pos + 2;

	if(rightChild < max) /* Has two children.*/
	{
		int smallestChildIndex = indexSmallest(heap, rightChild, leftChild);
		TYPE smallestChildValue = dyArrayGet(heap, smallestChildIndex);
		TYPE positionValue = dyArrayGet(heap, pos);
		if (positionValue > smallestChildValue)
		{
			swap(heap, smallestChildIndex, pos);
			_adjustHeap(heap, max, smallestChildIndex);
		}
	}

	else if (leftChild < max) /* Has one child.*/
	{
		TYPE childValue = dyArrayGet(heap, leftChild);
		TYPE positionValue = dyArrayGet(heap, pos);
		if (positionValue > childValue)
		{
			swap(heap, leftChild, pos);
			_adjustHeap(heap, max, leftChild);
		}
	}

	/* If execution is still going, there is no children, and no adjustment is necessary.*/
}

void heapAdd(struct dyArray * heap, TYPE newValue)
{
	int parent;
	int position = sizeDynArr(heap);
	dyArrayAdd(heap, newValue);

	while (position != 0)
	{
		parent = (position - 1) / 2;
		TYPE parentValue = dyArrayGet(heap, parent);
		TYPE positionValue = dyArrayGet(heap, position);

		if (positionValue < parentValue)
		{
			swap(heap, parent, position);
			position = parent;
		}
	}

	return;
}

