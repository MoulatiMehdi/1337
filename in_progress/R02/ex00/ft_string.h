/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:57:07 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/13 18:57:10 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 *	add zeros at the start of the string if possible
 *
 */
char	*ft_pad_start(char *s, int max, char c)
{
	int		len;
	int		i;
	char	*p;

	len = ft_strlen(s);
	i = 0;
	if (max < len)
		max = len;
	p = (char *)malloc(sizeof(char) * (max + 1));
	if (p == NULL)
		return (NULL);
	while (i < max - len)
		p[i++] = c;
	while (i < max)
	{
		p[i] = s[len - max + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}


char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

#endif
