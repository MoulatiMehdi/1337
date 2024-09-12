/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/12 15:22:40 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_list.h"
#include "stdlib.h"
#include "string.h"
#include "utils.h"

typedef struct s_request
{
	char			*desc;
	t_array			list1;
	char			*expected;
}					t_request;

void	ft_list_reverse_fun(t_list *begin_list);

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head;

	init_response(&res, req->desc);
	head = create_list(req->list1);
	ft_list_reverse_fun(head);
	res.is_pass = 1;
	ft_list_tostring(res.result,&head);
	sprintf(res.expected,"%s",req->expected);
	if(strcmp(res.result,res.expected))
		res.is_pass = 0;
	clear_list(head);
	return (res);
}

void	test_list_reverse_fun(void)
{
	int			size;

	char *strs[][10] = {
		{"A"},
		{"A", "E"},
		{"E", "A"},
		{"B", "C", "A"},
		{"A", "B", "C", "D"},
		{"D", "C", "B", "A"},
		{"A", "C", "B", "D"},
		{"D", "B", "C", "A"},
		{"D", "D", "D", "D"},
		{"D", "A", "D", "A"},
		{"B", "A", "C", "D"},
		{"A", "B", "D", "C"},
		{"strawberry", "watermelon", "apple", "kiwi", "banana", "cherry", "grape", "mango", "peach", "orange"},
	};
	t_array cases[] = {
		{.strs=NULL,.length=-1},
		{.strs=NULL,0},
		{strs[0],1},
		{strs[1],2},
		{strs[2],2},
		{strs[3],3},
		{strs[4],4},
		{strs[5],4},
		{strs[6],4},
		{strs[7],4},
		{strs[8],4},
		{strs[9],4},
		{strs[10],4},
		{strs[11],4},
		{strs[12],10},
	};
	t_request tests[] = {
		{.desc = "Both Null list", .list1 = cases[0], .expected = "Null"},
		{.desc = "Empty List", .list1 = cases[1], .expected = "Null"},
		{.desc = "One Element",  .list1 = cases[2], .expected = "A -> Null"},
		{.desc = "Two Element - Sorted", .list1 = cases[3], .expected = "E -> A -> Null"},
		{.desc = "Two Element - Reversed", .list1 = cases[4], .expected = "A -> E -> Null"},
		{.desc = "Three element List", .list1 = cases[5], .expected = "A -> C -> B -> Null"},
		{.desc = "Four element list - Sorted", .list1 = cases[6], .expected = "D -> C -> B -> A -> Null"},
		{.desc = "Four element list - Reversed", .list1 = cases[7], .expected = "A -> B -> C -> D -> Null"},
		{.desc = "Four element list - Swap Inner", .list1 = cases[8], .expected = "D -> B -> C -> A -> Null"},
		{.desc = "Four element list - Swap Outer", .list1 = cases[9], .expected = "A -> C -> B -> D -> Null"},
		{.desc = "Four element list - All Same", .list1 = cases[10], .expected = "D -> D -> D -> D -> Null"},
		{.desc = "Four element list - 2 Same", .list1 = cases[11], .expected = "A -> D -> A -> D -> Null"},
		{.desc = "Four element list - Swap Left", .list1 = cases[12], .expected = "D -> C -> A -> B -> Null"},
		{.desc = "Four element list - Swap Right", .list1 = cases[13], .expected = "C -> D -> B -> A -> Null"},
		{.desc = "10 Fruit list - Random", .list1 = cases[14], .expected = "orange -> peach -> mango -> grape -> cherry -> banana -> kiwi -> apple -> watermelon -> strawberry -> Null"},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex15/ft_list_reverse_fun", tests, is_test_passed, size,
		sizeof(tests[0]));
}
