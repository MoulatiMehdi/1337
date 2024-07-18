/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:28:53 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/17 22:29:29 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_grid
{
	char		**data;
	int			width;
	int			height;
	char		empty;
	char		full;
	char		ostacle;
}				t_grid;

int min(int a , int b,int c);
void			init_matrix(int **mtrx, struct s_grid map);
int				**create_matrix(int height, int width);
char			**create_strs(int height, int width);
void			find_max_square(struct s_grid map);
struct s_grid	init_map(char *p, int rows, int cols);

void			find_max_square(struct s_grid map);
void			print_data(struct s_grid map);
void			copy_data(struct s_grid M, char **map);
void			free_grid(void **arr_2d, int height);

char			*read_file(char *filename);
int				solve(int *x, int *y);
void			ft_putstr(char *str);
int				ft_strlen(char *str);

#endif
