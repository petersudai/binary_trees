#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: pointer to root node of tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Description: if tree or func is NULL, do nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* recursively traverse left subtree */
	binary_tree_inorder(tree->left, func);

	/* call func on current node */
	func(tree->n);

	/* recursively traverse right subtree */
	binary_tree_inorder(tree->right, func);
}
