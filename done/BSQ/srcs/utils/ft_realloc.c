/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:50:03 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 21:06:36 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	*ft_realloc(void *mem, int size)
{
	void	*new_mem;
	int		i;

	i = 0;
	new_mem = malloc(size);
	if (!new_mem)
		return (0);
	if (mem)
		while (i < size)
		{
			((char *)new_mem)[i] = ((char *)mem)[i];
			i++;
		}
	free(mem);
	return (new_mem);
}
