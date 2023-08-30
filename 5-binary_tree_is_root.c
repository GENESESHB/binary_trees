#include "binary_trees.h"
/**
 *binary_tree_is_root -  a function that checks if a given node is a root.
 *@node: the node to be checked if it is a root.
 *Return: 1 in succes otherwise 0.
 *
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->parent)
		return (1);
	else
		return (0);
}

