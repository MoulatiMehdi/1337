/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:30:31 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/18 16:30:32 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	**create_matrix(int rows, int cols)
{
	int	**arr;
	int	i;

	arr = (int **)malloc(sizeof(int *) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		arr[i] = (int *)malloc(sizeof(int) * cols);
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void	init_matrix(int **matrx, struct s_grid map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		matrx[i][0] = (map.data[i][0] == map.empty);
		i++;
	}
	i = 0;
	while (i < map.width)
	{
		matrx[0][i] = (map.data[0][i] == map.empty);
		i++;
	}
}

void	free_grid(void ***arr_2d)
{
	int	i;

	i = 0;
	if (!*arr_2d)
		return ;
	while (((*arr_2d)[i]) != NULL)
	{
		free((*arr_2d)[i]);
		(*arr_2d)[i] = NULL;
		i++;
	}
	*arr_2d = NULL;
	arr_2d = NULL;
}
