#include "binary_trees.h"
/**
 *binary_tree_node - a function that creates a binary
 *tree node.
 *@parent: a pointer to the parent node of the node to be created.
 *@value: the value of n of the new node.
 *Return: a pointer to the created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = new_node->right = NULL;
	return (new_node);
}
