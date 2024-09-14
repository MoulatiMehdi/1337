/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:04:19 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/14 02:39:29 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int		btree_level_count(t_btree *root);

void	get_next(t_btree ***curr_lvl, int len)
{
	t_btree	**next_lvl;
	int		i;
	int		j;

	next_lvl = 0;
	if (len > 0)
	{
		i = 0;
		j = 0;
		next_lvl = malloc(sizeof(t_btree *) * (len + 1));
		while (j < len)
		{
			if ((*curr_lvl)[i]->left)
				next_lvl[j++] = (*curr_lvl)[i]->left;
			if ((*curr_lvl)[i]->right)
				next_lvl[j++] = (*curr_lvl)[i]->right;
			i++;
		}
		next_lvl[j] = 0;
	}
	if (*curr_lvl)
		free(*curr_lvl);
	*curr_lvl = next_lvl;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_btree	**curr_lvl;
	int		level;
	int		i;
	int		j;

	if (!root)
		return ;
	curr_lvl = malloc(sizeof(t_btree *) * 2);
	curr_lvl[0] = root;
	curr_lvl[1] = 0;
	level = 0;
	while (curr_lvl)
	{
		i = 0;
		j = 0;
		while (curr_lvl[i])
		{
			(*applyf)(curr_lvl[i]->item, level, i == 0);
			j += curr_lvl[i]->left != 0;
			j += curr_lvl[i]->right != 0;
			i++;
		}
		get_next(&curr_lvl, j);
		level++;
	}
}
