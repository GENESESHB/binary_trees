#include "binary_trees.h"

/**
 * is_bst_util -function use recrisieve for virified if tree is BST
 * @tree: pointer for root tree
 * @prev: pointer for next node
 *
 * return: 1 if tree BST atherwise 0
 */

int is_bst_util(const binary_tree_t *tree, const binary_tree_t *prev)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_util(tree->left, prev))
		return (0);

	if (prev != NULL && tree->n <= prev->n)
		return (0);

	prev = tree;

	return(is_bst_util(tree->right, prev);
}

/**
 * binary_tree_is_bst - Vérifie si un arbre binaire est un ARB valide.
 * @tree: Pointeur vers le nœud racine de l'arbre à vérifier.
 *
 * Retourne : 1 si l'arbre est un ARB valide, 0 sinon.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    return is_bst_util(tree, NULL);
}
