/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:44:14 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/07 19:44:14 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_skip(t_list **prev, t_list *curr, t_list **begin_list2,
		int (*cmp)())
{
	t_list	*tmp;

	while ((*begin_list2)->next && (*cmp)((*begin_list2)->next->data,
		curr->data) <= 0)
		*begin_list2 = (*begin_list2)->next;
	*prev = *begin_list2;
	tmp = (*begin_list2)->next;
	(*begin_list2)->next = curr;
	*begin_list2 = tmp;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;

	if (!begin_list2)
		return ;
	if (!begin_list1 || !*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	curr = *begin_list1;
	prev = 0;
	while (begin_list2)
	{
		while (curr && (*cmp)(curr->data, begin_list2->data) < 0)
		{
			prev = curr;
			curr = curr->next;
		}
		if (!prev)
			prev->next = begin_list2;
		else
			*begin_list1 = begin_list2;
		ft_list_skip(&prev, curr, &begin_list2, cmp);
	}
}
