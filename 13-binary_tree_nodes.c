#include "binary_trees.h"
/**
 *binary_tree_nodes -  a function that counts the nodes with at least
 *1 child in a binary tree.
 *@tree: a pointer to the root.
 *Return: the total number of nodes with at least 1 child .
 *
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);


	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	if (!tree->left || !tree->right || (tree->left && tree->right))
		count++;
	return (count);
}
