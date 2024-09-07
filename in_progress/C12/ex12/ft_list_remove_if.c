/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:44:49 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/07 19:44:49 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*prev;

	if (!begin_list || !*begin_list)
		return ;
	curr = *begin_list;
	while (curr && (*cmp)(data_ref, curr->data) == 0)
	{
		free_fct(curr->data);
		*begin_list = curr->next;
		free(curr);
		curr = *begin_list;
	}
	while (curr)
	{
		if ((*cmp)(data_ref, curr->data) == 0)
		{
			free_fct(curr->data);
			prev->next = curr->next;
			free(curr);
		}
		else
			prev = curr;
		curr = prev->next;
	}
}
