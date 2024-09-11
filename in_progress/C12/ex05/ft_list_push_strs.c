/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:45:25 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 14:12:59 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*p;
	t_list	*new_elem;
	int		i;

	if (size <= 0 || !strs)
		return (0);
	i = 0;
	p = 0;
	while (i < size)
	{
		new_elem = ft_create_elem(strs[i]);
		if (!new_elem)
			break ;
		new_elem->next = p;
		p = new_elem;
		i++;
	}
	return (p);
}
