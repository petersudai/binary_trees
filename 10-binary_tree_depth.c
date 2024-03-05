#include "binary_trees.h"

/**
 * binary_tree_depth - Measures depth of node in binary tree
 * @tree: Pointer to node to measure depth of
 *
 * Return: Depth of node, 0 if tree is NULL or if node is root
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	/* Traverse up tree until reaching root */
	while (tree && tree->parent)
	{
		/* Move to parent node */
		tree = tree->parent;

		/* Increment the depth */
		depth++;
	}

	return (depth);
}
