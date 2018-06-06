// Worksheet 29

struct Node * _nodeAddBST(struct Node *current, TYPE newValue)
{
	struct Node * newNode;
	if (current == 0)
	{
		newNode = (struct Node *) malloc(sizeof(struct Node));
		assert(newNode != 0);

		newNode->value = newValue;
		newNode->left = newNode->right = 0;

		return newNode;
	}

	else if (newValue < current->Value)
	{
		current->left = _nodeAddBST(current->left, newValue)
	}

	else
	{
		current->right = _nodeAddBST(current->left, newValue)
	}

	return current;
}

int containsBST(struct BinarySearchTree *tree, TYPE d)
{
	struct Node* current = tree->root;

	while (current != 0)
	{
		if (current->value == d)
		{
			return 1;
		}

		else if (d < current->value)
		{
			current = current->left;
		}

		else
		{
			current = current->right;
		}

	}

	return 0;
}

TYPE _leftMostChild(struct Node * current)
{
	while (current->left != 0)
	{
		current = current->left;
	}

	return current->value;
}

struct Node * _removeLeftmostChild(struct Node *current)
{
	struct Node *temp;

	if (current->left == 0) /* base case */
	{
		temp = current->right;
		free(current);
		return temp;
	}

	/* Recursive part here. */

	current->left = _removeLeftmostChild(current->left);
	return current;

}

struct Node * _nodeRemoveBST(struct Node * current, TYPE d)
{
	
	struct Node *temp;

	if (current->value == d) /* Target value found.*/
	{
		if (current->right == 0) /* If there is no right child to the node targeted for
								 removal, we return the left child after removing the target.*/
		{
			temp = current->left;
			free(current); /* Freeing parameter node instead of temp, just like in _removeLeftmostChild.*/
			return temp;
		}

		else 
		{
			current->value = _leftMostChild(current->right); /* Replace the value of current with the leftmost child of the right branch.*/
			current->right = _removeLeftmostChild(current->right); /* Recursively removes the leftmost child of the right branch,
																   in order to prevent duplicates.*/
		}
	}

	/* If we haven't found the target, we now call the function recursively on the left and right 
	children of the root depending on wether the value of the node is lesser or greater than the parameter.*/
	else if (current->value < d)
	{
		current->right = _nodeRemoveBST(current->right, d);
	}

	else
	{
		current->left = _nodeRemoveBST(current->left, d);
	}

	return current;
}