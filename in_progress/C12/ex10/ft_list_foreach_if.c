/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:45:07 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/07 19:45:07 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	if (!begin_list || !f || !*f)
		return ;
	while (begin_list)
	{
		if ((*cmp)(data_ref, begin_list->next) == 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
