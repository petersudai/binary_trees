#include "binary_trees.h"

/**
 * create_avl_node - creates a new AVL node
 *
 * @value: the value to sotre in node
 *
 * Return: A pointer to the new AVL node
 */
avl_t *create_avl_node(int value)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));

	if (new_node)
	{
		new_node->n = value;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = NULL;
		new_node->height = 1;
	}
	return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: a pointer to root node of the created AVL tree, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t mid;
	avl_t *root;

	if (size == 0)
		return (NULL);

	mid = size / 2;
	root = create_avl_node(array[mid]);

	if (!root)
		return (NULL);

	root->left = sorted_array_to_avl(array, mid);
	if (root->left)
		root->left->parent = root;

	root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
	if (root->right)
		root->right->parent = root;

	return (root);
}
