#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements on the array
 *
 * Return: Pointer to root node of the created AVL tree, or
 * NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t i;

	root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (avl_insert(&root, array[i]) == NULL)
		{
			binary_tree_delete(root);
			return (NULL);
		}
	}
	return (root);
}
