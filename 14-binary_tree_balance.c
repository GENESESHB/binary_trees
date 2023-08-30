#include "binary_trees.h"
/**
 *binary_tree_height - a function that measures the height of a binary tree.
 *@tree: a pointer to the root node.
 *Return: the height of the tree otherwise 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (!tree)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);

	return (lh > rh ? lh + 1 : rh + 1);
}
/**
 *binary_tree_balance -  a function that measures the balance
 *factor of a binary tree.
 *@tree: a pointer to the root.
 *Return: the balance otherwise 0 .
 *
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);
	return (lh - rh);
}
