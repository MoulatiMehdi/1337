/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_apply_infix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:53:30 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 01:46:30 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

typedef struct s_request
{
	char			*desc;
	t_tree			arr[20];
	char			*expected;
}					t_request;

void				btree_apply_infix(t_btree *root, void (*applyf)(void *));

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_btree		*root;

	init_response(&res, req->desc);
	memset(g_buffer, 0, 1024);
	root = create_tree(req->arr);
	btree_apply_infix(root, print);
	strcpy(res.expected, req->expected);
	strcpy(res.result, g_buffer);
	if (strcmp(res.expected, res.result) == 0)
		res.is_pass = 1;
	clear_tree(root);
	return (res);
}

void	test_apply_infix(void)
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
			.expected = "A->",
		},
		{
			.desc = "Only Root node - Left Null",
			.arr = {{.item = "A", .left = -1, .right = 1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
			.expected = "A->B->",
		},
		{
			.desc = "Only Root node - Right Null",
			.arr = {{.item = "A", .left = 1, .right = -1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
			.expected = "B->A->",
		},
		{
			.desc = "Tree length : 1",
			.arr = {{.item = "A", .left = 1, .right = 2}, {.item = "B", .left =
				-1, .right = -1}, {.item = "C", .left = -1, .right = -1},
				g_null},
			.expected = "B->A->C->",
		},
		{
			.desc = "Number binary tree",
			.arr = {{.item = "1", .left = 1, .right = 2}, {.item = "2",
				.left = 3, .right = 4}, {.item = "3", .left = 5, .right = 6},
				{.item = "4", .left = -1, .right = -1}, {.item = "5", .left =
				-1, .right = -1}, {.item = "6", .left = -1, .right = -1},
				{.item = "7", .left = -1, .right = -1}, g_null},
			.expected = "4->2->5->1->6->3->7->",
		},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex02/btree_apply_infix", tests, is_test_passed, size,
		sizeof(tests[0]));
}
