/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_level_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:53:30 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 01:57:06 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

typedef struct s_request
{
	char			*desc;
	t_tree			arr[20];
	int				expected;
}					t_request;

int					btree_level_count(t_btree *root);

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_btree		*root;
	int			level;

	init_response(&res, req->desc);
	root = create_tree(req->arr);
	level = btree_level_count(root);
	sprintf(res.expected, "%d", req->expected);
	sprintf(res.result, "%d", level);
	if (strcmp(res.expected, res.result) == 0)
		res.is_pass = 1;
	clear_tree(root);
	return (res);
}

void	test_level_count(void)
{
	int	size;

	t_request tests[] = {
		{
			.desc = "NULL Root",
			.arr = {g_null},
			.expected = 0,
		},
		{
			.desc = "Only Root Node",
			.arr = {{.item = "A", .left = -1, .right = -1}, g_null},
			.expected = 1,
		},
		{
			.desc = "btree level 2 - Left Null",
			.arr = {{.item = "A", .left = -1, .right = 1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
			.expected = 2,
		},
		{
			.desc = "btree level 2 - Right Null",
			.arr = {{.item = "A", .left = 1, .right = -1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
			.expected = 2,
		},
		{
			.desc = "btree Level 2",
			.arr = {{.item = "A", .left = 1, .right = 2}, {.item = "B", .left =
				-1, .right = -1}, {.item = "C", .left = -1, .right = -1},
				g_null},
			.expected = 2,
		},
		{
			.desc = "Number binary tree",
			.arr = {{.item = "1", .left = 1, .right = 2}, {.item = "2",
				.left = 3, .right = 4}, {.item = "3", .left = 5, .right = 6},
				{.item = "4", .left = -1, .right = -1}, {.item = "5", .left =
				-1, .right = -1}, {.item = "6", .left = -1, .right = -1},
				{.item = "7", .left = -1, .right = -1}, g_null},
			.expected = 3,
		},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex06/btree_level_count", tests, is_test_passed, size,
		sizeof(tests[0]));
}
