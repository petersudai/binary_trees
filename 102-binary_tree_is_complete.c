#include "binary_trees.h"

/**
 * binary_tree_is_complete_recursive - checks if binary tree is
 * complete recursively
 * @tree: a pointer to root node of tree to check
 * @index: index of current node
 * @count: total no. of nodes in tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete_recursive(const binary_tree_t *tree,
		size_t index, size_t count)
{
	/* If tree is empty, it's considered complete */
	if (tree == NULL)
		return (1);

	/*
	 * If index of current node is greater than or equal to count
	 * of nodes, the tree is not complete
	 */
	if (index >= count)
		return (0);

	/* Recursuvely check the left and right subtrees */
	return (binary_tree_is_complete_recursive(tree->left, 2 * index + 1, count)
			&& binary_tree_is_complete_recursive(tree->right, 2 * index + 2, count));
}

/**
 * binary_tree_count - counts number of nodes in a binary tree
 * @tree: pointer to root node of the tree
 *
 * Return: number of nodes in the tree
 */
size_t binary_tree_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_count(tree->left) + binary_tree_count(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_is_complete_recursive(tree, 0, binary_tree_count(tree)));
}
