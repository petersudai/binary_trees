#include "binary_trees.h"

/**
 * binary_tree_enqueue - Enqueues a node into binary treee queue
 * @front: double pointer to front of the queue
 * @node: pointer to node to enqueue
 */

void binary_tree_enqueue(binary_tree_queue_t **front,
                binary_tree_queue_t *node)
{
	binary_tree_queue_t *temp = *front;

	if (*front == NULL)
	{
		*front = node;
		return;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
}

/**
 * binary_tree_levelorder_traverse - Helper function to traverse tree
 * using level-order traversal
 * @tree: pointer to current node
 * @func: pointer to a function to call for each node
 */

void binary_tree_levelorder_traverse(const binary_tree_t *tree,
		void (*func)(int))
{
	if (tree == NULL)
		return;

	binary_tree_enqueue((binary_tree_queue_t **)&tree,
			(binary_tree_queue_t *)tree);
	while (tree != NULL)
	{
		func(tree->n);
		if (tree->left != NULL)
			binary_tree_enqueue((binary_tree_queue_t **)&tree,
					(binary_tree_queue_t *)tree->left);
		if (tree->right != NULL)
			binary_tree_enqueue((binary_tree_queue_t **)&tree,
					(binary_tree_queue_t *)tree->right);
		tree = tree->next;
	}
}

/**
 * binary_tree_levelorder - goes through binary tree using
 * level order traversal
 * @tree: pointer to root node of the tree to traverse
 * @func: pointer to a function for each node
 *
 * Description: if tree of func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_levelorder_traverse(tree, func);
}
