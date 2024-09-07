/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:44:39 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/07 19:44:39 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap_items(t_list *p_prev, t_list **p, t_list *q_prev,
		t_list **q)
{
	t_list	*tmp;

	if (!q || !p || !*q || !*p)
		return ;
	if (p_prev)
		p_prev->next = *q;
	if (q_prev)
		q_prev->next = *p;
	tmp = (*q)->next;
	(*q)->next = (*p)->next;
	(*p)->next = tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*p;
	t_list	*q;
	t_list	*p_prev;
	t_list	*q_prev;

	if (!cmp || !*cmp || !begin_list || !*begin_list)
		return ;
	p = *begin_list;
	p_prev = 0;
	while (p->next)
	{
		q_prev = p;
		q = p->next;
		while (q)
		{
			if ((*cmp)(p->data, q->data) > 0)
				ft_list_swap_items(p_prev, &p, q_prev, &q);
			q_prev = q;
			q = q->next;
		}
		p_prev = p;
		p = p->next;
	}
}
