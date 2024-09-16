/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:57:15 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 22:27:41 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_btree.h"
#include <stdlib.h>

char	g_buffer[1024] = {0};
t_tree	g_null = {.item = {0}, .left = -2, .right = -2};

t_btree	*create_tree(t_tree *arr_t)
{
	t_btree	**nodes;
	t_btree	*root;
	int		size;
	int		i;
	int		id;

	root = 0;
	size = 0;
	if (!arr_t)
		return (0);
	while (arr_t[size].left != -2 && arr_t[size].right != -2)
		size++;
	if (size <= 0)
		return (0);
	i = 0;
	nodes = malloc((size) * sizeof(t_btree *));
	while (i < size)
	{
		nodes[i] = btree_create_node(arr_t[i].item);
		i++;
	}
	i = 0;
	while (i < size)
	{
		id = arr_t[i].left;
		if (id >= 0 && id < size)
			nodes[i]->left = nodes[id];
		else
			nodes[i]->left = 0;
		id = arr_t[i].right;
		if (id >= 0 && id < size)
			nodes[i]->right = nodes[id];
		else
			nodes[i]->right = 0;
		i++;
	}
	root = nodes[0];
	free(nodes);
	return (root);
}

void	clear_tree(t_btree *root)
{
	if (!root)
		return ;
	clear_tree(root->left);
	clear_tree(root->right);
	free(root);
}

void	print(void *item)
{
	strcat(g_buffer, item ? (char *)item : "Null");
	strcat(g_buffer, "->");
}

void	print_level(void *item, int current_level, int is_first_elem)
{
	char	nbr[20] = {0};

	if (is_first_elem)
	{
		if (current_level != 0)
		{
			strcat(g_buffer, "\n");
		}
		sprintf(nbr, "%d:", current_level);
		strcat(g_buffer, nbr);
	}
	print(item);
}
