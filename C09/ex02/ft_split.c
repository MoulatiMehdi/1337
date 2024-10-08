/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:18:18 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:18:27 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *src, int n)
{
	char	*p;
	int		size;
	int		i;

	i = 0;
	if (src == NULL || n == 0)
		return (0);
	size = ft_strlen(src);
	if (n < size)
		size = n;
	p = (char *)malloc((size + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	while (i < size)
	{
		p[i] = src[i];
		i++;
	}
	p[size] = '\0';
	return (p);
}

int	ft_index(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_count_word(char *str, char *charset)
{
	int	count;

	if (charset == NULL || str == NULL || str[0] == '\0')
		return (0);
	count = 0;
	while (*str)
	{
		while (ft_index(charset, *str) != -1)
			str++;
		if (*str)
		{
			count++;
			while (*str && ft_index(charset, *str) == -1)
				str++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		size;
	int		i;
	int		end;

	i = 0;
	size = ft_count_word(str, charset);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strs)
		return (0);
	while (i < size)
	{
		end = 0;
		while (ft_index(charset, *str) != -1)
			str++;
		while (str[end] && ft_index(charset, str[end]) == -1)
			end++;
		if (*str)
			strs[i] = ft_strndup(str, end);
		str += end;
		i++;
	}
	strs[size] = 0;
	return (strs);
}
