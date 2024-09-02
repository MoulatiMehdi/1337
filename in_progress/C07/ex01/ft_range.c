/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:17:46 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:17:48 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	p = (int *)malloc(sizeof(int) * (max - min));
	if (p == NULL)
		return (NULL);
	while (min + i < max)
	{
		p[i] = min + i;
		i++;
	}
	return (p);
}
