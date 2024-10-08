/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:37 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 20:49:38 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

struct s_grid	init_grid(char **map)
{
	struct s_grid	grid;
	char			*sets;

	sets = get_sets(map[0]);
	grid.height = get_height(map[0]);
	grid.width = ft_strlen(map[1]);
	grid.data = &map[1];
	grid.empty = sets[0];
	grid.ostacle = sets[1];
	grid.full = sets[2];
	free(map[0]);
	map[0] = NULL;
	return (grid);
}

void	print_grid(struct s_grid map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		write(1, map.data[i], map.width);
		write(1, "\n", 1);
		i++;
	}
}

struct s_grid	create_grid(char *str)
{
	struct s_grid	grid;
	char			**table;

	grid.data = NULL;
	if (str == NULL)
		return (grid);
	table = ft_split(str, "\n");
	if (!is_valid_data(table))
		return (grid);
	grid = init_grid(table);
	return (grid);
}
