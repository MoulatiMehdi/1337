/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:45:23 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 15:31:13 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*p;

	p = begin_list;
	while (p)
	{
		if (free_fct)
			free_fct(p->data);
		p = p->next;
		free(begin_list);
		begin_list = p;
	}
}
