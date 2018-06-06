/*************************
** rotateLeft and rotateRight methods were adapted line for line from the psudeocode
** provided on AVL_Trees2.pdf, slide 5 / 19.
**
** The remove function is very similar to the one we did in Worksheet 29, but we adjust
** the return calls for the functions to apply the _balance() function to the current node first.
** Reminder that this removal method uses the functional approach where recursive calls build up the
** tree.
*************************/


struct AVLnode * _rotateLeft(struct AVLnode * current) 
{
	struct AVLnode *newTop = current->right; /* Rule 1: Newtop is equal to current node's right child.*/
	current->right = newTop->left; /* Rule 2: Current node's new right child is new top's (old right child's) left child.*/
	newTop->left = current; /* Rule 3: New top's left child is the current node.*/
	_setHeight(current); /* Rule 4: Set height of current node.*/
	_setHeight(newTop); /* Rule 5: Set height of new top node.*/
	return newTop; /* Rule 6: Return new top node.*/
}

/* Code for the rotateRight is just an exact mirror of the above rotateLeft code. */

struct AVLnode * _rotateRight(struct AVLnode * current)
{
	struct AVLnode *newTop = current->left; /* Mirrored rule 1: Newtop is equal to current node's left child.*/
	current->left = newTop->right; /* Mirrored rule 2: Current node's new left child is new top's (old left child's) right child.*/
	newTop->right = current; /* Mirrored Rule 3: New top's right child is the current node.*/

	/* After the first 3 rules, mirroring doesn't matter.*/

	_setHeight(current); /* Rule 4: Set height of current node. */
	_setHeight(newTop); /* Rule 5: Set height of new top node.*/
	return newTop; /* Rule 6: Return new top node.*/
}

struct AVLNode * _removeNode(struct AVLNode *cur, TYPE val)
{
	struct AVLNode *temp; /* Just like in worksheet 29, we construct a temp node.*/

	/* Here, I do cur->value instead of cur-> val because of how worksheet 31 specifies the AVLNode structure.
	In most instances of AVL trees, the value section of the structure is called val, but in this worksheet, it
	is called value, so I conform to that. */

	if (EQ(val, cur->value)) 
	{
		if (cur->right == 0) /* If current node doesn't have a right node, we will return the left child after removing target. */
		{
			temp = current->left; /* Setting temp to left child of current because we are returning it later.*/
			free(cur); /* We are freeing the parameter instead of temp because we want to return the left child.*/
			return temp; 
		}

		else /* If execution reaches here, current node has a right child.*/
		{
			/* We are replacing current with the left most child of right branch,
			just like with binary search trees.*/
			cur->value = _leftMost(cur->right); /* _leftMost() returns the value of the left most child, and we assign it to cur->value. */
			cur->right = _removeLeftmost(cur->right); /* Although we have assigned current node the value of the left most child, we call this
													  function to recursively remove the actual leftmost child, in order to prevent duplicates.*/
			return _balance(cur); /* Returns the current node after balancing the tree.*/
		}
	}

	/* At this point, we have covered the removal function if the target is found, so now we use recursive calls to 
	cover the traversal of the function through the tree.*/

	else if (LT(val, current->value))
	{
		/* In cases where the the value we are searching for is less than the value of the current node, we need to
		traverse left through the tree. We can do this by calling the _removeNode function recursively, with
		cur->left as the parameter. */

		cur->left = _removeNode(cur->left, val);
	}

	else
	{
		/* In cases where the value we are searching for is greater than the value of the current node or equal, we traverse
		right through the tree by calling the _removeNode function recursively, with cur->right as the parameter.*/
		cur->right = _removeNode(cur->right, val);
	}

	/* The only function calls that will reach this return in the execution are the calls to the function that
	traverse the tree. Here, we return the balanced form of the current node so that the various recursive calls 
	to remove node can use it to rebuild the tree. */

	return _balance(cur);
}