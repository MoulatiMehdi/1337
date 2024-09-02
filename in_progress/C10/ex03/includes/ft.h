/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:25:44 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 14:26:19 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		count_option(char **argv, int argc, char *str);
char	**get_files(char **argv, int argc);

int		ft_strcmp(char *str1, char *str2);
void	ft_putstr(char *str);
void	read_input(int repeat);
void	read_file(char **files, int repeat);

void	ctoh(unsigned char c);
void	str_to_hex(char *str, char sep);
void	int_to_hex(int addr);
