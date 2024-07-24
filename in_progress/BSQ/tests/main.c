#include "ft.h"
#include "stdio.h"

char **create_strs(int rows, int cols);
int main()
{
    char **map;

    map = create_strs(2,2);

    map[0][0] = '.';
    map[0][1] = '.';
    map[1][0] = '.';
    map[1][1] = '.';
    struct s_grid grid;

    grid.data = map;
    grid.width = 2;
    grid.height = 2;
    grid.empty = '.';
    grid.full = 'x';
    grid.ostacle = 'o';

    find_max_square(grid);
    ft_putstr(grid.data[0]);
    ft_putstr(grid.data[1]);
    return 0;
}