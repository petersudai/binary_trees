#include "binary_trees.h"

/**
 * binary_tree_is_avl_recursive - check if a binary tree is a valid
 * AVL tree recursively
 * @tree: a pointer to root node of the tree
 * @min: the minimum value node can take
 * @max: the maximum value node can take
 * @height: the height of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */

int binary_tree_is_avl_recursive(const binary_tree_t *tree,
		int min, int max, int *height)
{
	int left_height, right_height;

	left_height = 0;
	right_height = 0;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	if (!binary_tree_is_avl_recursive(tree->left, min, tree->n - 1,
				&left_height) || !binary_tree_is_avl_recursive(tree->right,
					tree->n + 1, max, &right_height))
		return (0);

	*height = (left_height > right_height ? left_height : right_height) + 1;

	if (abs(left_height - right_height) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVL tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	height = 0;

	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_recursive(tree, INT_MIN, INT_MAX, &height));
}
