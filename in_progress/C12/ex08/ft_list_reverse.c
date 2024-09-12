/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:45:18 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/07 19:45:18 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*curr;
	t_list	*prev;

	if (!begin_list || !*begin_list || !(*begin_list)->next)
		return ;
	prev = 0;
	curr = *begin_list;
	while (curr)
	{
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	*begin_list = prev;
}
