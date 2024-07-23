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

int is_valid_set(char *set)
{
	int len = ft_strlen(set);
	if (len != 3)
		return 0;
	if (set[0] == set[1] || set[1] == set[2] || set[0] == set[2])
		return 0;

	return 1;
}

int is_valid_map(char **str, int rows, char *set)
{
	int i;
	int j;
	int cols;

	cols = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_index(set, str[i][j]) < 0)
				return 0;
			j++;
		}
		if (j != cols)
			return 0;
		i++;
	}
	return (i == rows);
}

int is_valid_info(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	if (len <= 3)
		return 0;
	i = 0;
	while (i < len - 3)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

int is_valid_data(char **data)
{
	int height;
	char *set;

	if (!is_valid_info(data[0]))
		return 0;
	height = get_height(data[0]);
	set = get_sets(data[0]);
	if (!is_valid_set(set) || height < 1)
		return 0;
	if (!is_valid_map(&data[1], height, set))
		return 0;

	return 1;
}