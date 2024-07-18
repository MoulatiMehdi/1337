/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:30:46 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/18 16:30:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_valid_set(char *set)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(set);
	if (len != 3)
		return (0);
	if (set[0] == set[1] || set[0] == set[2] || set[1] == set[2])
		return (0);
	while (i < len)
	{
		if (set[i] < 32 || set[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_valid(char **str, int rows, int cols)
{
	int	i;
	int	len;

	i = 0;
	while (i < rows)
	{
		len = ft_strlen(str[i]);
		if (len != cols)
			return (0);
	}
	return (1);
}
