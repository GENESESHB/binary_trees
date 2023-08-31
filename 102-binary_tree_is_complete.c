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
 *binary_tree_is_leaf - a function that checks if a node
 *is a leaf.
 *@node: the node to be checked.
 *Return: 1 in succes otherwise 0.
 *
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);
	else
		return (0);
}
/**
 *binary_tree_is_perfect -  a function that checks if a binary tree is perfect.
 *@tree: a pointer to the root .
 *Return: 1 if it is perfect otherwise 0.
 *
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{

	if (!tree)
		return (1);
	if (binary_tree_is_leaf(tree))
		return (1);
	if (!tree->left || !tree->right)
		return (0);
	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		if (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right))
			return (1);
	}
	return (0);
}

/**
 *binary_tree_is_complete - a function that checks if a
 *binary tree is complete.
 *@tree: the root node of the tree.
 *Return: 1 if the binary tree is complete otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (!tree)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);

	lheight = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);
	if (lheight == rheight)
	{
		if (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_complete(tree->right))
			return (1);
	}
	if (lheight == rheight + 1)
	{
		if (binary_tree_is_complete(tree->left) &&
				binary_tree_is_perfect(tree->right))
			return (1);
	}

	return (0);
}
