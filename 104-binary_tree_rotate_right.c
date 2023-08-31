#include "binary_trees.h"
/**
 *binary_tree_rotate_right - a function that performs a right-rotation
 *on a binary tree.
 *@tree: a pointer to the root node of the tree to rotate.
 *Return: a pointer to the new root node of the tree once rotated.
 *
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);

	if (tree->left)
	{
		temp = tree->left->right;
		tree->left->parent = tree->parent;
		tree->parent = tree->left;
		tree->left->right = tree;
		tree->left = temp;
		if (temp)
			temp->parent = tree;
		return (tree->parent);
	}
	return (NULL);
}
