/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:17:53 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:17:55 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	p = (int *)malloc(sizeof(int) * (max - min));
	if (p != NULL)
	{
		while (min + i < max)
		{
			p[i] = min + i;
			i++;
		}
	}
	return (p);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (*range == NULL)
		return (-1);
	return (max - min);
}
