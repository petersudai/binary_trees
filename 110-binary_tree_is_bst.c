#include "binary_trees.h"

/**
 * check_bst - helper function to check if a binary tree is a valid BST
 * @tree: a pointer to root node of the tree to check
 * @prev: a pointer to previously visited node's value
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int check_bst(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!check_bst(tree->left, prev))
		return (0);

	if (*prev != -1 && tree->n <= *prev)
		return (0);

	*prev = tree->n;

	return (check_bst(tree->right, prev));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev;

	prev = -1;

	if (tree == NULL)
		return (0);

	return (check_bst(tree, &prev));
}
