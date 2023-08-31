#include "binary_trees.h"
/**
 *is_valid_bst - a function that checks if a binary tree is
 *a valid Binary Search Tree (BST).
 *@node: a pointer to the current node being evaluated.
 *@prev_node: a pointer to a pointer to the previously visited node.
 *Return: 1 if the tree is a valid BST otherwise 0.
 *
 */
int is_valid_bst(const binary_tree_t *node, const binary_tree_t **prev_node)
{
	if (node == NULL)
		return (1);

	if (!is_valid_bst(node->left, prev_node))
		return (0);

	if ((*prev_node) && node->n <= (*prev_node)->n)
		return (0);

	*prev_node = node;

	return (is_valid_bst(node->right, prev_node));
}
/**
 *binary_tree_is_bst - a function that checks if a binary tree
 *is a valid Binary Search Tree.
 *@tree: a pointer to the root of the binary tree.
 *Return: 1 in succes otherwise 0.
 *
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *prev_node = NULL;

	if (!tree)
		return (0);

	return (is_valid_bst(tree, &prev_node));
}
