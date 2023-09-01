#include "binary_trees.h"
/**
 *bst_remove -  a function that removes a node from a BST.
 *@root: a pointer to the root node of the BST.
 *@value: the value to be removed.
 *Return:  a pointer to the new root node of the tree after
 *removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 *bst_find_min - a function that helps to find the minimum node in a BST.
 *@node: a pointer to the root node of the subtree to search.
 *Return: a pointer to the minimum node in the subtree.
 */
bst_t *bst_find_min(bst_t *node)
{
	while (node->left)
		node = node->left;

	return (node);
}


