/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:02:54 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/13 22:21:39 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
			void *))
{
	void	*target;

	if (!cmpf || !root)
		return (0);
	target = btree_search_item(root->left, data_ref, cmpf);
	if (target)
		return (target);
	if (cmpf(data_ref, root->item))
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
