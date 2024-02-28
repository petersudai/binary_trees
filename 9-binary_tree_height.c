#include "binary_trees.h"

/**
 * binary_tree_height - measures height of binary tree
 * @tree: pointer to root of tree to measure height
 *
 * Return: height of tree, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	/* Base case: empty tree has height 0 */
	if (tree == NULL)
		return (0);

	/* recursively get the height of the left subtree */
	left_height = binary_tree_height(tree->left);

	/* recursively get height of right subtree */
	right_height = binary_tree_height(tree->right);

	/* return height of taller subtree, plus 1 for current node */
	return (1 + (left_height > right_height ? left_height : right_height));
}
