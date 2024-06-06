#include "binary_trees.h"
/**
 * binary_tree_nodes - How many nodes on a tree.
 * @tree: Root node of tree.
 * Return: Number of nodes.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t nodes_right, nodes_left;

	if (tree == NULL)
		return (0);

	nodes_left = binary_tree_nodes(tree->left) + 1;
	nodes_right = binary_tree_nodes(tree->right) + 1;
	return (nodes_right + nodes_left - 1);

}
/**
 * is_complete - Is binary tree complete using index & num nodes.
 * @tree: The root node.
 * @index: Index of node.
 * @nodes: Number of nodes.
 * Return: 0 or 1
 */
int is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, nodes) &&
		is_complete(tree->right, 2 * index + 2, nodes));
}
/**
 * binary_tree_is_complete - Is binary tree complete (all to left).
 * @tree: Root node.
 * Return: 1 if true 0 if false.
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;
	size_t nodes = binary_tree_nodes(tree);

	if (tree == NULL)
		return (0);

	return (is_complete(tree, index, (int)nodes));
}
