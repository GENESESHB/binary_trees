#include "binary_trees.h"
/**
 *bst_search - a function that searches for a value in a Binary Search Tree.
 *@tree: a pointer to the root node of the BST to search.
 *@value: the value to search in the tree.
 *Return: a pointer to the node containing a value equals to value
 *otherwise NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *left_result, *right_result;

	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n > value)
	{
		left_result = bst_search(tree->left, value);
		if (left_result)
			return (left_result);
	}
	else
	{
		right_result = bst_search(tree->right, value);
		if (right_result)
			return (right_result);
	}
	return (NULL);
}
