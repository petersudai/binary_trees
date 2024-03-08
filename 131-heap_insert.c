#include "binary_trees.h"

/**
 * heapify_up - moves a node up to its correct position in the Max Heap
 * @node: A pointer to the node to heapify up
 */
void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node-> = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to root node of the Heap to insert value
 * @value: The value to store in node to be inserted
 * Return: A pointer to created node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	parent = *root;
	while (parent->left && parent->right)
	{
		if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
			parentt = parent->left;
		else
			parent = parent->right;
	}

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;
	heapify_up(new_node);

	return (new_node);
}
