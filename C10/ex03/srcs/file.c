/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:35:24 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/03 14:35:24 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	open_file(char *filename, int oflag)
{
	int	fd;

	fd = open(filename, oflag);
	if (fd < 0)
		ft_errno(filename);
	return (fd);
}

int	close_file(int fd, char *filename)
{
	int	res;

	res = close(fd) < 0;
	if (res < 0)
		ft_errno(filename);
	return (res);
}

int	read_file(int fd, char *buffer, int buff_size, char *filename)
{
	int	bytes;

	bytes = read(fd, buffer, buff_size);
	if (bytes < 0)
		ft_errno(filename);
	return (bytes);
}
