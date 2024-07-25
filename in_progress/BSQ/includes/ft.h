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
#define FT_H

#define BUFF_SIZE 1024

#include <fcntl.h>
#include "ft_utils.h"

typedef struct s_grid
{
	char **data;
	int width;
	int height;
	char empty;
	char full;
	char ostacle;
} t_grid;

// allocate
int	**create_matrix(int rows, int cols);
void	init_matrix(int **matrx, struct s_grid map);
void	free_grid(void ***arr_2d);

// map.c
void print_grid(struct s_grid map);
struct	s_grid create_grid(char *str);

// solve
void solve(char *str);

// parse & validate
int is_valid_data(char **data);
char *get_sets(char *str);
int get_height(char *str);

// read
char *read_input();
char *read_file(char *filename);
#endif
