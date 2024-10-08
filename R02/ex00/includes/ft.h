/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:54:51 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 20:55:07 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H 
# define FT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		lookup(char *str);
void	populate(char *str, char ***dict);
// parse
char	*read_dict(char *dict_filename);
char	*parse_number(char *str);
int		parse_string(char *dictionary_string, char ****dict);

// convert
int		num_to_words(char *numStr, char *buffer);
int		convert_hundred(char *numStr, char *buffer);
int		convert_ten_unit(char *numStr, char *buffer);
int		convert_to_words(char *number, char *buffer);

// print

void	print_error(char *str);
void	print_zero(void);
// utils
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);

#endif
