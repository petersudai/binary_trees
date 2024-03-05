#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: pointer to root node of tree to measure the size
 *
 * Return: size of the tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Recursive call to count the size of left and right subtrees */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
