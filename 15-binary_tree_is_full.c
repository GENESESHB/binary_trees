#include "binary_trees.h"
/**
 *binary_tree_is_full -  a function that checks if a binary tree is full.
 *@tree: a pointer to the root .
 *Return: 1 in succes otherwise 0.
 *
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	if (!tree->left && !tree->right)
		return (1);
	return (0);
}
