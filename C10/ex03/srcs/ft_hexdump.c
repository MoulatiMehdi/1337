/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:25:10 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/05 13:25:13 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_hexdump(char **files, char *buffer, int repeat)
{
	int	i;
	int	fd;
	int	count;
	int	byte;

	count = 0;
	i = 0;
	while (files[i])
	{
		byte = 1;
		fd = open_file(files[i], O_RDONLY);
		while (fd >= 0 && byte > 0)
		{
			byte = read_file(fd, &buffer[count % 16], 16 - count % 16,
					files[i]);
			if (byte < 0)
				break ;
			count += byte;
			if (count % 16 == 0)
				print_canonical(buffer, count - 16, repeat);
		}
		close_file(fd, files[i]);
		i++;
	}
	print_rest(buffer, count, repeat);
}

void	read_input(char *buffer, int repeat)
{
	int		byte;
	char	prev_buff[17];
	int		count;
	int		is_exit;

	is_exit = 0;
	count = 0;
	byte = 1;
	while (byte > 0)
	{
		byte = read_file(0, &buffer[count % 16], 16 - count % 16, "");
		if (byte < 0)
			return ;
		count += byte;
		if (count % 16 != 0 || is_printed(buffer, prev_buff, &is_exit))
			continue ;
		is_exit = 0;
		print_canonical(buffer, count - 16, repeat);
		ft_strcpy(prev_buff, buffer);
	}
	print_rest(buffer, count, repeat);
}
