#include "binary_trees.h"

/**
 * avl_insert -inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			if ((*tree)->left == NULL)
				return (NULL);
			node = (*tree)->left;
		}
		else
			node = avl_insert(&((*tree)->left), value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			if ((*tree)->right == NULL)
				return (NULL);
			node = (*tree)->right;
		}
		else
			node = avl_insert(&((*tree)->right), value);
	}
	else
		return (NULL);

	binary_tree_balance(*tree);

	return (node);
}
