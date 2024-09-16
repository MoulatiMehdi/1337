/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:24:06 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 00:13:34 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include "ft_btree.h"
# include "utils.h"
# include <stdio.h>
# include <stdlib.h>

extern char		g_buffer[1024];
typedef struct s_tree
{
	void		*item;
	int			left;
	int			right;
}				t_tree;

extern t_tree	g_null;
t_btree			*create_tree(t_tree *arr_t);
void			clear_tree(t_btree *root);
void			print(void *item);

#endif
