#include "binary_trees.h"
/**
 *binary_trees_ancestor -  a function that finds the lowest
 *common ancestor of two nodes.
 *@first: one of the nodes to find their lowest common ancestor.
 *@second:one of the nodes to find their lowest common ancestor.
 *Return: a pointer to the lowest common ancestor.
 *
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{

	binary_tree_t *temp = (binary_tree_t *)second;
	binary_tree_t *fir = (binary_tree_t *)first;
	binary_tree_t *sec = (binary_tree_t *)second;

	if (!first || !second || !first->parent || !second->parent)
		return (NULL);

	while (fir)
	{
		while (sec)
		{
			if (fir == sec)
				return (fir);
			sec = sec->parent;
		}
		sec = temp;
		fir = fir->parent;
	}
	return (NULL);
}
