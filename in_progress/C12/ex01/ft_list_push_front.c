/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:27:56 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/10 01:17:41 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	if(!begin_list)
		return ;
	new_elem = ft_create_elem(data);
	if (!new_elem)
		return ;
	if (begin_list && *begin_list)
		new_elem->next = *begin_list;
	*begin_list = new_elem;
}
