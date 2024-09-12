/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:44:29 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/07 19:44:29 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap_data(t_list *p, t_list *q)
{
	void	*tmp;

	tmp = p->data;
	p->data = q->data;
	q->data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		size;
	t_list	*p;
	t_list	*q;

	if (!begin_list || !begin_list->next)
		return ;
	size = ft_list_size(begin_list);
	i = 0;
	p = begin_list;
	while (i * 2 < size)
	{
		p = p->next;
		i++;
	}
	i = size / 2 - 1;
	while (p)
	{
		q = ft_list_at(begin_list, i);
		ft_list_swap_data(p, q);
		i--;
		p = p->next;
	}
}
