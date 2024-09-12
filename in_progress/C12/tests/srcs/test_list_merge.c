/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/12 12:44:07 by mmoulati         ###   ########.fr       */
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
}					t_request;

void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);
static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head_1;
	t_list		*head_2;
	t_list		*tmp;
	int			i;

	init_response(&res, req->desc);
	head_1 = create_list(req->list1);
	head_2 = create_list(req->list2);
	ft_list_merge(req->list1.length == -1 ? NULL : &head_1, head_2);
	res.is_pass = 1;
	tmp = head_1;
	i = 0;
	while (tmp)
	{
		if (i < req->list1.length)
		{
			if (tmp->data != req->list1.strs[i])
			{
				res.is_pass = 0;
				sprintf(res.result, "item (%d) : %s", i, (char *)tmp->data);
				sprintf(res.expected, "item (%d) : %s", i, req->list1.strs[i]);
				break ;
			}
		}
		else if (i < req->list1.length + req->list2.length
			&& tmp->data != req->list2.strs[i - req->list1.length])
		{
			res.is_pass = 0;
			sprintf(res.result, "item (%d) : %s", i, (char *)tmp->data);
			sprintf(res.expected, "item (%d) : %s", i, req->list2.strs[i
				- req->list1.length]);
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	if (res.is_pass && req->list1.length != -1 &&req->list2.length != -1 && req->list1.length + req->list2.length != i)
	{
		res.is_pass = 0;
		sprintf(res.result, "size : %d", i);
		sprintf(res.expected, "size : %d", req->list1.length
			+ req->list2.length);
	}
	clear_list(head_1);
	return (res);
}

void	test_list_merge(void)
{
	int			size;


	char *strs[][10] = {
		{"A"},{"A", "E"},
		{"A", "B", NULL},
		{"A", "B", "C", NULL},
		{NULL, NULL, NULL, NULL}
	};
	t_array cases[] = {
		{.strs=NULL,.length=-1},
		{.strs=NULL,0},
		{strs[0],1},
		{strs[1],2},
		{strs[2],3},
		{strs[3],3},
		{strs[4],3},
	};
	t_request	tests[] = {
		{.desc = "Both Null list", .list1= cases[0], .list2=cases[1]},
		{.desc = "Empty List", .list1 = cases[1], .list2=cases[1]},
		{.desc = "One Element - List2 Empty", .list1=cases[1], .list2=cases[2]},
		{.desc = "One Element - List1 Empty", .list2=cases[2], .list1=cases[1]},
		{.desc = "Two element List", .list1=cases[1], .list2=cases[1]},
		{.desc = "Three element List", .list1=cases[2], .list2=cases[2]},
		{.desc = "Four element list", .list1=cases[3], .list2=cases[4]},
		{.desc = "All items are Null", .list1=cases[4], .list2=cases[3]}
	};

	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex13/ft_list_merge", tests, is_test_passed, size,
		sizeof(tests[0]));
}
