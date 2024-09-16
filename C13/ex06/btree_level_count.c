/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:22:08 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/13 23:03:50 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	len1;
	int	len2;

	if (!root)
		return (0);
	len1 = btree_level_count(root->left);
	len2 = btree_level_count(root->right);
	if (len1 < len2)
		len1 = len2;
	return (len1 + 1);
}
