#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to node to check
 *
 * Return: 1 if its a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* check if node is NULL */
	if (node == NULL)
		return (0);

	/* check if node has no children */
	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}
