/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:55:42 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/02 21:22:27 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

char	***g_numbers;

int	main(int argc, char *argv[])
{
	char	*dict_name;
	char	*input;
	char	*dict_str;
	char	***dict;
	char	buffer[2048];

	buffer[0] = '\0';
	dict_name = "default.dict";
	input = parse_number(argv[argc - 1]);
	if (input == NULL)
		return (print_error("Error\n"));
	if (argc == 3)
		dict_name = argv[1];
	dict_str = read_dict(dict_name);
	if (dict_str == NULL || !parse_string(dict_str, &dict))
		return (print_error("Dict Error\n"));
	g_numbers = dict;
	if (input[0] == '0')
		print_zero();
	else if (convert_to_words(input, buffer))
		printf("%s\n", buffer);
	return (0);
}
