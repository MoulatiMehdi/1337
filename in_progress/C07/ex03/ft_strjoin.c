/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:17:58 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:18:00 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_cat(char *dest, char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	return (j);
}

int	ft_total_size(char **strs, int size, char *sep)
{
	int	len;

	if (!strs)
		return (0);
	len = 0;
	if (size > 1)
		len += (size - 1) * ft_strlen(sep);
	while (size > 0)
	{
		len += ft_strlen(strs[size - 1]);
		size--;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	if (sep == NULL || size < 0)
		return (NULL);
	len = ft_total_size(strs, size, sep);
	i = 0;
	j = 0;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < size - 1)
	{
		j += ft_cat(p + j, strs[i++]);
		j += ft_cat(p + j, sep);
	}
	if (size > 0)
		j += ft_cat(p + j, strs[i]);
	p[j] = '\0';
	return (p);
}
