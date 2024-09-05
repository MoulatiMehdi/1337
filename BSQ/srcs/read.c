/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:28:58 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/18 02:28:13 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*get_text(int fd)
{
	char	tmp_buff[BUFF_SIZE];
	int		bytes;
	char	*buffer;
	int		len;
	int		j;

	j = 0;
	len = 0;
	buffer = NULL;
	while (1)
	{
		bytes = read(fd, tmp_buff, BUFF_SIZE);
		if (bytes < 1)
			break ;
		buffer = ft_realloc(buffer, sizeof(char) * (len + bytes + 1));
		j = 0;
		while (j < bytes)
		{
			buffer[len + j] = tmp_buff[j];
			j++;
		}
		len += bytes;
	}
	buffer[len] = '\0';
	return (buffer);
}

char	*read_file(char *filename)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_text(fd);
	close(fd);
	return (str);
}

char	*read_input(void)
{
	return (get_text(0));
}
