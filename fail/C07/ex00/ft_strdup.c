/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:17:40 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/12 20:17:41 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (NULL);
	size = ft_strlen(src);
	p = (char *)malloc((size + 1) * sizeof(char));
	if (p != NULL)
	{
		while (i < size)
		{
			p[i] = src[i];
			i++;
		}
		p[size] = '\0';
	}
	return (p);
}
