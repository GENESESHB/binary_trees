#include  "binary_trees.h"
/**
 *binary_tree_rotate_left - a function that perform
 *s a left-rotation on a binary tree.
 *@tree:a pointer to the root node of the tree to rotate.
 *Return:a pointer to the new root node of the tree once rotated.
 *
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree)
		return (NULL);
	if (tree->right)
	{
		tmp = tree->right->left;
		tree->right->parent = tree->parent;
		tree->right->left = tree;
		tree->parent = tree->right;
		tree->right = tmp;
		if (tmp)
			tmp->parent = tree;
		return (tree->parent);
	}
	return (NULL);
}
