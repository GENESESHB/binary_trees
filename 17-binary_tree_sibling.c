#include "binary_trees.h"
/**
 *binary_tree_sibling -  a function that finds the sibling of a node.
 *@node: the node to find its sibling.
 *Return: a pointer to the sibling node otherwise NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->right != node)
		return (node->parent->right);
	else
		return (node->parent->left);
	return (NULL);
}
