#include "binary_trees.h"
/**
 *
 *
 *
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp;

	if (!(*tree))
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);

	}
	temp = (*tree);
	while (temp)
	{
		if (temp->n == value)
			break;
		if (temp->n > value)
		{
			if (!temp->left)
			{
				temp->left = (bst_t *)binary_tree_node(temp, value);
				return (temp->left);
			}
			temp = temp->left;
		}
		if (temp->n < value)
		{
			if(!temp->right)
			{
				temp->right = (bst_t *)binary_tree_node(temp, value);
				return (temp->right);
			}
			temp = temp->right;
		}
	}
	return (NULL);
}







