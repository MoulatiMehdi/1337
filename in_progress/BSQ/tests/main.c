#include "ft.h"
#include "test.h"


void fail(char *desc, char **expected, char **result);
void pass(char *desc);
int compate_maps(char **map1, char **map2);
void print_grid(struct s_grid grid);

int main(void)
{
    struct s_grid grid;

    grid = create_grid("2.ox\n.o\n.o\n");

   if(grid.data) 
    print_grid(grid);
    else
    printf("(null)");
}

