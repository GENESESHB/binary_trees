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
 *apply_func_to_nodes_at_level - a function that applies a specific function to
 *nodes at a specific level of the tree.
 *@tree: a pointer to the root node of the tree.
 *@level: the level of the tree at which to apply the function.
 *@func: a pointer to the function to apply to node values.
 *Return: void.
 */
void apply_func_to_nodes_at_level(const binary_tree_t *tree
		, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	if (level > 0)
	{
		apply_func_to_nodes_at_level(tree->left, level - 1, func);
		apply_func_to_nodes_at_level(tree->right, level - 1, func);
	}
}
/**
 *binary_tree_levelorder -  a function that goes through a binary
 *tree using level-order traversal.
 *@tree: a pointer to the root node of the tree.
 *@func: a pointer to the function to apply to node values.
 *Return: void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
		apply_func_to_nodes_at_level(tree, i, func);
}
