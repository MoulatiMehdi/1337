/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:25:44 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/05 14:46:40 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FUNC_NAME "ft_hexdump"

char	**get_files(char **argv, int argc);
char	*ft_strcpy(char *dest, char *src);

int		ft_errno(char *filename);
int		close_file(int fd, char *filename);
int		open_file(char *filename, int oflag);
int		read_file(int fd, char *buffer, int buff_size, char *filename);
int		count_option(char **argv, int argc, char *str);
int		ft_strcmp(char *str1, char *str2);
int		is_printed(char *buffer, char *prev_buff, int *is_exit);

void	ft_putchar(unsigned char c);
void	ft_putstr(char *str);
void	str_to_hex(char *str, char sep);
void	int_to_hex(unsigned int addr, int bytes);
void	ctoh(unsigned char c);
void	sanitize(char *str);
void	read_input(char *buffer, int repeat);
void	ft_hexdump(char **files, char *buffer, int repeat);
void	print_canonical(char *str, int addr, int repeat);
void	print_rest(char *buffer, int count, int repeat);
