/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_apply_by_level.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:53:30 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 17:30:57 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

typedef struct s_request
{
	char			*desc;
	t_tree			arr[20];
	char			*expected;
}					t_request;

void				btree_apply_by_level(t_btree *root,
						void (*applyf)(void *item, int current_level,
							int is_first_elem));
static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_btree		*root;

	init_response(&res, req->desc);
	memset(g_buffer, 0, 1024);
	root = create_tree(req->arr);
	btree_apply_by_level(root, print_level);
	strcpy(res.expected, req->expected);
	strcpy(res.result, g_buffer);
	if (strcmp(res.expected, res.result) == 0)
		res.is_pass = 1;
	clear_tree(root);
	return (res);
}

void	test_apply_by_level(void)
{
	int	size;

	t_request tests[] = {
		{
			.desc = "NULL Root",
			.arr = {g_null},
			.expected = "",
		},
		{
			.desc = "Only Root Node",
			.arr = {{.item = "A", .left = -1, .right = -1}, g_null},
			.expected = "0:A->",
		},
		{
			.desc = "Only Root node - Left Null",
			.arr = {{.item = "A", .left = -1, .right = 1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
			.expected = "0:A->\n1:B->",
		},
		{
			.desc = "Only Root node - Right Null",
			.arr = {{.item = "A", .left = 1, .right = -1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
			.expected = "0:A->\n1:B->",
		},
		{
			.desc = "Tree length : 1",
			.arr = {{.item = "A", .left = 1, .right = 2}, {.item = "B", .left =
				-1, .right = -1}, {.item = "C", .left = -1, .right = -1},
				g_null},
			.expected = "0:A->\n1:B->C->",
		},
		{
			.desc = "Number binary tree",
			.arr = {{.item = "1", .left = 1, .right = 2}, {.item = "2",
				.left = 3, .right = 4}, {.item = "3", .left = 5, .right = 6},
				{.item = "4", .left = -1, .right = -1}, {.item = "5", .left =
				-1, .right = -1}, {.item = "6", .left = -1, .right = -1},
				{.item = "7", .left = -1, .right = -1}, g_null},
			.expected = "0:1->\n1:2->3->\n2:4->5->6->7->",
		},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex07/btree_apply_by_level", tests, is_test_passed, size,
		sizeof(tests[0]));
}
