#include "binary_trees.h"
/**
 *binary_tree_insert_right - a function that inserts a node on the right side
 *of the parent node.
 *@parent: the parent node of the inserted node.
 *@value: the n value of the inserted node.
 *Return: a pointer to the inserted node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (parent->right)
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
	}
	parent->right = new_node;
	return (new_node);
}
