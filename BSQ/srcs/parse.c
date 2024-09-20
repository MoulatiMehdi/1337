/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:42 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 20:49:45 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_height(char *str)
{
	int	height;
	int	len;
	int	i;

	height = 0;
	len = ft_strlen(str);
	i = 0;
	while (i < len - 3)
	{
		height = height * 10 + str[i] - '0';
		i++;
	}
	return (height);
}

char	*get_sets(char *str)
{
	return (str + ft_strlen(str) - 3);
}
