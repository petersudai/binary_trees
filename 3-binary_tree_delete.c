#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of tree to delete
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		/* Recursively delete left and right subtrees */
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->rght);

		/* Delete current node */
		free(tree);
	}
}
