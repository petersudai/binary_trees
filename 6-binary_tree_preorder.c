#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to root node of tree to traverse
 * @func: pointer to function to call for each node
 *
 * Description: if tree of func is NULL, do nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Call func on the current node */
	func(tree->n);

	/* recursively traverse left subtree */
	binary_tree_preorder(tree->left, func);

	/* recursively traverse right subtree */
	binary_tree_preorder(tree->right, func);
}
