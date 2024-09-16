/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:55:02 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 20:34:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	test_create_node(void);
void	test_apply_prefix(void);
void	test_apply_suffix(void);
void	test_apply_infix(void);
void	test_level_count(void);
void	test_apply_by_level(void);
void	test_insert_data(void);
void	test_search_item(void);

int	main(void)
{
	test_create_node();
	test_apply_prefix();
	test_apply_infix();
	test_apply_suffix();
	test_insert_data();
	test_search_item();
	test_level_count();
	test_apply_by_level();
}
