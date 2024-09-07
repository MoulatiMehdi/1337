/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:44:44 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/07 19:44:44 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*p;

	if (!begin_list2)
		return ;
	if (!begin_list1 || !*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	p = *begin_list1;
	while (p->next)
		p = p->next;
	p->next = begin_list2;
}
