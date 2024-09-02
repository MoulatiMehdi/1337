/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:08:59 by mmoulati          #+#    #+#             */
/*   Updated: 2024/07/06 20:09:02 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	srclen;

	srclen = 0;
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[srclen])
		srclen++;
	if (size > 0)
	{
		while (j + i < size - 1 && src[j])
		{
			dest[j + i] = src[j];
			j++;
		}
		dest[j + i] = '\0';
	}
	if (i < size)
		size = i;
	return (srclen + size);
}
