/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:52:51 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 21:11:25 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFF_SIZE 1024
# define L_ARROW "==>"
# define R_ARROW "<=="

void		read_file(char *filename, long long bytes);
void		read_input(long long bytes);

long long	parse_num(char *str);
long long	get_bytes(char **argv, int argc);
char		**get_files(char **argv, int argc);

void		print_name(char *filename);
void		error(char *filename, int errnum);
void		ft_puterr(char *str);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *);
#endif
