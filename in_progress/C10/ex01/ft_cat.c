/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:31:58 by mmoulati          #+#    #+#             */
/*   Updated: 2024/08/23 14:28:07 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(char *str, int stream);
void	error(char *filename);

int	read_file(char *filename)
{
	int		fd;
	int		bytes;
	char	buffer[30];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error(filename);
		return (-1);
	}
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 30);
		write(1, buffer, bytes);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		read_file(argv[i]);
		i++;
	}
}

void	ft_putstr(char *str, int stream)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(stream, str, i);
	return ;
}

void	error(char *filename)
{
	ft_putstr("./ft_cat: ", 2);
	ft_putstr(filename, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}
