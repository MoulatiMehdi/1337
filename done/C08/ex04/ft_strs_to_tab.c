/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:00:21 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 10:04:43 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		size;
	int		i;

	i = 0;
	if (src == NULL)
		return (0);
	size = ft_strlen(src);
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

void	ft_free_all(struct s_stock_str **arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i].str != 0)
	{
		free((*arr)[i].copy);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*strs;
	int					i;

	if (ac < 0)
		return (NULL);
	strs = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		strs[i].size = ft_strlen(av[i]);
		strs[i].str = av[i];
		strs[i].copy = ft_strdup(av[i]);
		if (strs[i].copy == NULL)
		{
			ft_free_all(&strs);
			return (NULL);
		}
		i++;
	}
	strs[ac].str = 0;
	strs[ac].copy = NULL;
	strs[ac].size = 0;
	return (strs);
}
