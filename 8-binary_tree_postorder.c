#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using post-order traversal
 * @tree: pointer to root node of tree to traverse
 * @func: pointer to a  function to call for each node
 *
 * Description: if tree of func is NULL, do nothing
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* recursively traverse left subtree */
	binary_tree_postorder(tree->left, func);

	/* recursively traverse right subtree */
	binary_tree_postorder(tree->right, func);

	/* call func on current node */
	func(tree->n);
}
