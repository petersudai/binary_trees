#include "binary_trees.h"

/**
 * is_heap - checks if a binary tree is a max binary heap
 * @tree: A pointer to root node of the binary tree
 *
 * Return: 1 if the binary tree is a max binary heap, otherwise 0
 */

int is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);
	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);
	return (is_heap(tree->left) && is_heap(tree->right));
}

/**
 * is_complete - Checks if a binary tree is a complete binary tree
 * @tree: A pointer to the root node of the binary tree
 * Return: 1 if the binary tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right != NULL)
        return (0);

    return (is_complete(tree->left) && is_complete(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_complete(tree))
		return (0);

	return (is_heap(tree));
}
