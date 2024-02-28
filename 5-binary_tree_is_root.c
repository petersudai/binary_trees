#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if node is a root
 * @node: pointer to node to check
 *
 * Return: 1 if its a root, 0 otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	/* check if node is NULL */
	if (node == NULL)
		return (0);

	/* check if node has no parent */
	if (node->parent == NULL)
		return (1);

	return (0);
}
