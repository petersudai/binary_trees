#include "binary_trees.h"

/**
 * binary_tree_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if
 * no common ancestor was found
 */
binary_tree_t *binary_tree_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *temp1 = first;
	const binary_tree_t *temp2 = second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (temp1)
	{
		temp2 = second;
		while (temp2)
		{
			if (temp1 == temp2)
				return ((binary_tree_t *)temp1);
			temp2 = temp2->parent;
		}
		tempt1 = temp1->parent;
	}
	return (NULL);
}
