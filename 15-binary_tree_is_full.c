#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of tree
 *
 * Return: 1 if tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If node has no children, it's a leaf and thus full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If both left and right children exist, check if they are full */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If only one child exists, the tree is not full */
	return (0);
}
