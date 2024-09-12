/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/12 14:44:15 by mmoulati         ###   ########.fr       */
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
	char* expected;
	int(*cmp)();
}					t_request;

void	ft_list_sort(t_list **begin_list, int (*cmp)());

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head_1;
	
	init_response(&res, req->desc);
	head_1 = create_list(req->list1);
	ft_list_sort(req->list1.length == -1 ? NULL : &head_1, req->cmp);
	res.is_pass = 1;
	ft_list_tostring(res.result,&head_1);
	sprintf(res.expected,"%s",req->expected);
	if(strcmp(res.result,res.expected)!= 0)
		res.is_pass = 0;
	clear_list(head_1);
	return (res);
}

void	test_list_sort(void)
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
	t_request	tests[] = {
		{.desc = "Both Null list", .list1= cases[0], .cmp=strcmp,.expected="Null"},
		{.desc = "Empty List", .list1 = cases[1], .cmp=strcmp,.expected="Null"},
		{.desc = "One Element", .cmp=strcmp, .list1=cases[2],.expected="A -> Null"},
		{.desc = "Two Element - Null cmp function", .list1=cases[4], .cmp=NULL,.expected="E -> A -> Null"},
		{.desc = "Two Element - Reversed", .list1=cases[4], .cmp=strcmp,.expected="A -> E -> Null"},
		{.desc = "Two Element - Sorted", .list1=cases[3], .cmp=strcmp,.expected="A -> E -> Null"},
		{.desc = "Three element List", .list1=cases[5], .cmp=strcmp,.expected="A -> B -> C -> Null"},
		{.desc = "Four element list - Null cmp function", .list1=cases[6], .cmp=NULL, .expected="A -> B -> C -> D -> Null"},
		{.desc = "Four element list - Sorted", .list1=cases[6], .cmp=strcmp,.expected="A -> B -> C -> D -> Null"},
		{.desc = "Four element list - Reversed", .list1=cases[7], .cmp=strcmp,.expected="A -> B -> C -> D -> Null"},
		{.desc = "Four element list - Swap Inner", .list1=cases[8], .cmp=strcmp,.expected="A -> B -> C -> D -> Null"},
		{.desc = "Four element list - Swap Outer", .list1=cases[9], .cmp=strcmp,.expected="A -> B -> C -> D -> Null"},
		{.desc = "Four element list - All Same", .list1=cases[10], .cmp=strcmp,.expected="D -> D -> D -> D -> Null"},
		{.desc = "Four element list - 2 Same", .list1=cases[11], .cmp=strcmp,.expected="A -> A -> D -> D -> Null"},
		{.desc = "Four element list - Swap Left", .list1=cases[12], .cmp=strcmp,.expected="A -> B -> C -> D -> Null"},
		{.desc = "Four element list - Swap Right", .list1=cases[13], .cmp=strcmp,.expected="A -> B -> C -> D -> Null"},
		{.desc = "10 Fruit list - Random", .list1=cases[14], .cmp=strcmp,.expected="apple -> banana -> cherry -> grape -> kiwi -> mango -> orange -> peach -> strawberry -> watermelon -> Null"},
	};

	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex14/ft_list_sort", tests, is_test_passed, size,
		sizeof(tests[0]));
}
