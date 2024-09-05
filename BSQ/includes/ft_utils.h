/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:49:13 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 20:49:17 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>
# include <unistd.h>

void	*ft_realloc(void *mem, int size);
void	ft_putstr(char *str);

int		ft_strlen(char *str);
int		min(int a, int b, int c);
int		ft_index(char *set, char c);

char	**ft_split(char *str, char *charset);

#endif
