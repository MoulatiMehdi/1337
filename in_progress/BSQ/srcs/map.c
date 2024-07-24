#include "ft_utils.h"

struct s_grid init_grid(char **map, int height, int width)
{
	struct s_grid grid;

	char *sets;

	sets = get_sets(map[0]);

	grid.height = height;
	grid.width = width;
	grid.data = create_strs(height, width);
	grid.empty = sets[0];
	grid.ostacle = sets[1];
	grid.full = sets[2];
	copy_grid(grid, &map[1]);

	return (grid);
}

void copy_grid(struct s_grid grid, char **map)
{
	int i;
	int j;

	i = 0;
	while (i < grid.height)
	{
		j = 0;
		while (j < grid.width)
		{
			grid.data[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

void print_grid(struct s_grid map)
{
	int i;
	int j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			write(1, &map.data[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

struct s_grid create_grid(char *str)
{
	struct s_grid grid;
	char **table;
	int height;
	int width;

	grid.data = NULL;
	if (str == NULL)
		return grid;
	table = ft_split(str, "\n");
	if (!is_valid_data(table))
	{
		ft_putstr("Map E");
		return grid;
	}

	grid = init_grid(table, height, width);
	print_grid(grid);
	return grid;
}
