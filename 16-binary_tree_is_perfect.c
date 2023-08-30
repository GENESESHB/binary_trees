#include "binary_trees.h"
/**
 *binary_tree_height - a function that measures the height of a binary tree.
 *@tree: a pointer to the root node.
 *Return: the height of the tree otherwise 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);

	return (lh > rh ? lh + 1 : rh + 1);
}

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
/**
 *binary_tree_is_perfect -  a function that checks if a binary tree is perfect.
 *@tree: a pointer to the root .
 *Return: 1 if it is perfect otherwise 0.
 *
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t  height = 0, size = 0, nodes = 1, i;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	for (i = 0; i <= height; i++)
		nodes *= 2;
	if (size == (nodes - 1))
		return (1);
	return (0);
}


