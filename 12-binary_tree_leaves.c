#include "binary_trees.h"
/**
 *binary_tree_leaves -  a function that counts the leaves in a binary tree.
 *@tree: a pointer to the root.
 *Return: the number of leaves otherwise 0.
 *
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);


	if (!tree->left && !tree->right)
	{
		return (1);
	}
	count += binary_tree_leaves(tree->left);
	count += binary_tree_leaves(tree->right);
	return (count);
}

