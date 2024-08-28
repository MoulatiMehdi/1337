/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:08:57 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/28 00:58:55 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

long long	file_size(char *filename)
{
	int			fd;
	char		buff[BUFF_SIZE];
	long long	size;
	long long	bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error(filename, errno);
		return (0);
	}
	bytes = 1;
	size = 0;
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFF_SIZE);
		size += bytes;
	}
	if (close(fd) < 0 || bytes < 0)
	{
		error(filename, errno);
		return (0);
	}
	return (size);
}

void	skip_read(int fd, long long bytes, char *filename)
{
	long long	size;
	char		c;

	size = file_size(filename);
	if (size < bytes)
		bytes = size;
	while (size > bytes)
	{
		read(fd, &c, 1);
		size--;
	}
}

void	read_file(char *filename, long long bytes)
{
	int		fd;
	int		read_bytes;
	char	buffer[BUFF_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error(filename, errno);
		return ;
	}
	print_name(filename);
	skip_read(fd, bytes, filename);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFF_SIZE);
		write(1, buffer, read_bytes);
	}
	if (close(fd) < 0 || read_bytes < 0)
		return (error(filename, errno));
}

void	read_input(long long bytes)
{
	(void)bytes;
}
