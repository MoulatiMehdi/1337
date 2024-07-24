/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:28:58 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/18 02:28:13 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

#define BUFF_SIZE 1024

long long file_size(char *filename)
{
	int fd;
	char buffer[BUFF_SIZE];
	long long size;
	int bytes;

	fd = open(filename, O_RDONLY);
	size = 0;
	bytes = 1;
	if (fd < 0)
		return (-1);
	while (1)
	{
		bytes = read(fd, buffer, BUFF_SIZE);
		if (bytes <= 0)
			break;
		size += bytes;
	}
	if (bytes < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (size);
}

char *read_file(char *filename)
{
	int fd;
	long long bytes;
	char *str;
	int size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	size = file_size(filename);
	if (size <= 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	bytes = read(fd, str, size);
	if (bytes < 0)
	{
		close(fd);
		free(str);
		return (str = NULL);
	}
	close(fd);
	str[size] = '\0';
	return (str);
}

char *read_input()
{
	char tmp_buff[BUFF_SIZE];
	char *buffer;
	int bytes;
	int len;
	int j;

	buffer = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (!buffer)
		return NULL;
	len = 0;
	while (1)
	{
		bytes = read(0, tmp_buff, BUFF_SIZE);
		if (bytes < 1)
			break;
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
	return buffer;
}
