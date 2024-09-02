/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:49:46 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/17 23:49:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*new_tab;

	new_tab = (int *)malloc(length * sizeof(int));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_tab[i] = (*f)(tab[i]);
		i++;
	}
	return (new_tab);
}
