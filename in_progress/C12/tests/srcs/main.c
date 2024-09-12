/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:26:46 by mehdi             #+#    #+#             */
/*   Updated: 2024/09/12 13:05:17 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	test_push_front(void);
void	test_create_elem(void);
void	test_push_back(void);
void	test_list_size(void);
void	test_list_last(void);
void	test_push_strs(void);
void	test_list_clear(void);
void	test_list_at(void);
void	test_list_reverse(void);
void	test_list_foreach(void);
void	test_list_foreach_if(void);
void	test_list_find(void);
void	test_list_remove_if(void);
void	test_list_merge(void);
void	test_list_sort(void);

int	main(void)
{
	test_create_elem();
	test_push_front();
	test_list_size();
	test_list_last();
	test_push_back();
	test_push_strs();
	test_list_clear();
	test_list_at();
	test_list_reverse();
	test_list_foreach();
	test_list_foreach_if();
	test_list_find();
	test_list_remove_if();
	test_list_merge();
	test_list_sort();
	return (0);
}
