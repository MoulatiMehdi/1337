/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:42:23 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/13 21:21:58 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "stdlib.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new_elem;

	new_elem = malloc(sizeof(t_btree));
	if (!new_elem)
		return (0);
	new_elem->left = 0;
	new_elem->right = 0;
	new_elem->item = item;
	return (new_elem);
}
