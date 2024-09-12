/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sorted_merge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/12 18:39:03 by mmoulati         ###   ########.fr       */
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
	t_array			list2;
	int				(*cmp)();
	char			*expected;
}					t_request;

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head_1;
	t_list		*head_2;

	init_response(&res, req->desc);
	head_1 = create_list(req->list1);
	head_2 = create_list(req->list2);
	ft_sorted_list_merge(req->list1.length == -1 ? NULL : &head_1, head_2, req->cmp);
	res.is_pass = 1;
	ft_list_tostring(res.result, &head_1);
	strcpy(res.expected, req->expected);
	if (strcmp(res.result, res.expected) != 0)
		res.is_pass = 0;
	clear_list(head_1);
	if(!req->cmp)
		clear_list(head_2);
	return (res);
}

void	test_sorted_list_merge(void)
{
	int			size;


	char *strs[][10] = {
		{"A"},
		{"A", "E"},
		{"D", "O", "P"},
		{"A", "C", "D", "Z"},
		{"A", "B", "C", "D"},
		{"W", "X", "Y", "Z"},
		{"A", "C", "E", "G"},
		{"B", "D", "F", "H"}
	};
	t_array cases[] = {
		{.strs=NULL,.length=-1},
		{.strs=NULL,0},
		{strs[0],1},
		{strs[1],2},
		{strs[2],3},
		{strs[3],4},
		{strs[4],4},
		{strs[5],4},
		{strs[6],4},
		{strs[7],4},
	};
	t_request	tests[] = {
		{.desc = "Both Null list", .list1= cases[0], .list2=cases[1],.cmp=strcmp,.expected="Null",},
		{.desc = "Empty List", .list1 = cases[1], .list2=cases[1],.cmp=strcmp,.expected="Null",},
		{.desc = "One item - List2 Empty", .list1=cases[1], .list2=cases[2],.cmp=strcmp,.expected="A -> Null",},
		{.desc = "One item - List1 Empty", .list2=cases[2], .list1=cases[1],.cmp=strcmp,.expected="A -> Null",},
		{.desc = "Null cmp Function", .list1=cases[2], .list2=cases[2],.cmp=NULL,.expected="A -> Null",},
		{.desc = "One item - Same Element", .list1=cases[2], .list2=cases[2],.cmp=strcmp,.expected="A -> A -> Null",},
		{.desc = "First item in List2", .list1=cases[4], .list2=cases[5],.cmp=strcmp,.expected="A -> C -> D -> D -> O -> P -> Z -> Null",},
		{.desc = "First item in List1", .list1=cases[5], .list2=cases[4],.cmp=strcmp,.expected="A -> C -> D -> D -> O -> P -> Z -> Null",},
		{.desc = "All List1 small then List2", .list1=cases[6], .list2=cases[7],.cmp=strcmp,.expected="A -> B -> C -> D -> W -> X -> Y -> Z -> Null",},
		{.desc = "All List1 bigger then List2", .list1=cases[7], .list2=cases[6],.cmp=strcmp,.expected="A -> B -> C -> D -> W -> X -> Y -> Z -> Null",},
		{.desc = "Random List Blend", .list1=cases[8], .list2=cases[9],.cmp=strcmp,.expected="A -> B -> C -> D -> E -> F -> G -> H -> Null",},
		{.desc = "Reverse Random List Blend", .list1=cases[9], .list2=cases[8],.cmp=strcmp,.expected="A -> B -> C -> D -> E -> F -> G -> H -> Null",},
	};

	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex17/ft_sorted_list_merge", tests, is_test_passed, size,
		sizeof(tests[0]));
}
