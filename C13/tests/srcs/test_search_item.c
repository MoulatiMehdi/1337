/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_search_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:53:30 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 22:26:38 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

typedef struct s_request
{
	char			*desc;
	t_tree			arr[20];
	int				(*cmpf)(const char *, const char *);
	void			*data_ref;
	void			*expected;
}					t_request;

void				*btree_search_item(t_btree *root, void *data_ref,
						int (*cmpf)(void *, void *));
static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_btree		*root;
	void		*item;

	init_response(&res, req->desc);
	memset(g_buffer, 0, 1024);
	root = create_tree(req->arr);
	item = btree_search_item(root, req->data_ref, (int (*)(void *,
					void *))req->cmpf);
	if (item == req->expected)
		res.is_pass = 1;
	else
	{
		sprintf(res.expected, "%p", req->expected);
		sprintf(res.result, "%p", item);
	}
	clear_tree(root);
	return (res);
}

void	test_search_item(void)
{
	int	size;

	t_request tests[] = {
		{
			.desc = "NULL Root",
			.arr = {g_null},
			.data_ref = "A",
			.cmpf = strcmp,
			.expected = 0,
		},
		{
			.desc = "Only Root Node",
			.data_ref = "A",
			.cmpf = strcmp,
			.expected = tests[1].arr[0].item,
			.arr = {{.item = "A", .left = -1, .right = -1}, g_null},
		},
		{
			.desc = "Only Root node - Left Null",
			.expected = 0,
			.cmpf = strcmp,
			.data_ref = "0",
			.arr = {{.item = "A", .left = -1, .right = 1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
		},
		{
			.desc = "Only Root node - Right Null",
			.expected = tests[3].arr[1].item,
			.cmpf = strcmp,
			.data_ref = "A",
			.arr = {{.item = "A", .left = 1, .right = -1}, {.item = "A", .left =
				-1, .right = -1}, g_null},
		},
		{
			.desc = "Tree length : 1",
			.expected = tests[4].arr[0].item,
			.data_ref = "A",
			.cmpf = strcmp,
			.arr = {{.item = "A", .left = 1, .right = 2}, {.item = "B", .left =
				-1, .right = -1}, {.item = "C", .left = -1, .right = -1},
				g_null},
		},
		{
			.desc = "Number binary tree",
			.data_ref = "2",
			.expected = tests[5].arr[1].item,
			.cmpf = strcmp,
			.arr = {{.item = "1", .left = 1, .right = 2}, {.item = "2",
				.left = 3, .right = 4}, {.item = "3", .left = 5, .right = 6},
				{.item = "4", .left = -1, .right = -1}, {.item = "5", .left =
				-1, .right = -1}, {.item = "6", .left = -1, .right = -1},
				{.item = "7", .left = -1, .right = -1}, g_null},
		},
		{
			.desc = "Nmber tree - incomplite tree",
			.data_ref = "7",
			.expected = tests[6].arr[6].item,
			.cmpf = strcmp,
			.arr = {{.item = "1", .left = 1, .right = -1}, {.item = "2",
				.left = 2, .right = -1}, {.item = "3", .left = 3, .right = 4},
				{.item = "4", .left = -1, .right = 5}, {.item = "5", .left = 6,
				.right = -1}, {.item = "6", .left = -1, .right = -1},
				{.item = "7", .left = -1, .right = -1}, g_null},
		},
		{
			.desc = "Number tree - incomplite tree Same Number",
			.data_ref = "7",
			.expected = tests[7].arr[3].item,
			.cmpf = strcmp,
			.arr = {{.item = "7", .left = 1, .right = -1}, {.item = "7",
				.left = 2, .right = -1}, {.item = "7", .left = 3, .right = 4},
				{.item = "7", .left = -1, .right = 5}, {.item = "7", .left = 6,
				.right = -1}, {.item = "7", .left = -1, .right = -1},
				{.item = "7", .left = -1, .right = -1}, g_null},
		},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex05/btree_search_item", tests, is_test_passed, size,
		sizeof(tests[0]));
}
