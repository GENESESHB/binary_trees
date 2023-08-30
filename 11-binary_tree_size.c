#include "binary_trees.h"
/**
 *binary_tree_size -  a function that measures the size of a binary tree.
 *@tree: a pointer to the root.
 *Return: the size of the tree otherwise 0.
 *
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);


	count += binary_tree_size(tree->left);
	count += binary_tree_size(tree->right);
	return (count + 1);
}
