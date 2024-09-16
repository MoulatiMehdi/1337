/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:28:56 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 17:47:51 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
			void *))
{
	t_btree	*new_elem;
	t_btree	**curr;

	if (!root || !cmpf)
		return ;
	new_elem = btree_create_node(item);
	if (!new_elem)
		return ;
	curr = root;
	while (*curr)
	{
		if (cmpf((*curr)->item, item) <= 0)
			curr = &(*curr)->right;
		else
			curr = &(*curr)->left;
	}
	*curr = new_elem;
}
