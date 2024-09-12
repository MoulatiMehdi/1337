/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:45:27 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/10 02:13:57 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*p;
	t_list	*new_elem;

	if (!begin_list)
		return ;
	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	if (!*begin_list)
	{
		*begin_list = new_elem;
		return ;
	}
	p = *begin_list;
	while (p->next)
		p = p->next;
	p->next = new_elem;
}
