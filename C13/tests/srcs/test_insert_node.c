/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_insert_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:53:30 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 22:26:12 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

typedef struct s_request
{
	char			*desc;
	t_tree			arr[20];
	int				(*cmpf)(const char *, const char *);
	void			*item;
	char			*expected;
}					t_request;

void				btree_apply_by_level(t_btree *root,
						void (*applyf)(void *item, int current_level,
							int is_first_elem));
void				btree_insert_data(t_btree **root, void *item,
						int (*cmpf)(void *, void *));
static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_btree		*root;

	init_response(&res, req->desc);
	memset(g_buffer, 0, 1024);
	root = create_tree(req->arr);
	btree_insert_data(&root, req->item, (int (*)(void *, void *))req->cmpf);
	btree_apply_by_level(root, print_level);
	strcpy(res.expected, req->expected);
	strcpy(res.result, g_buffer);
	if (strcmp(res.expected, res.result) == 0)
		res.is_pass = 1;
	clear_tree(root);
	return (res);
}

void	test_insert_data(void)
{
	int	size;

	t_request tests[] = {
		{
			.desc = "NULL Root",
			.arr = {g_null},
			.item = "A",
			.cmpf = strcmp,
			.expected = "0:A->",
		},
		{
			.desc = "Only Root Node",
			.item = "A",
			.cmpf = strcmp,
			.expected = "0:A->\n1:A->",
			.arr = {{.item = "A", .left = -1, .right = -1}, g_null},
		},
		{
			.desc = "Only Root node - Left Null",
			.expected = "0:A->\n1:B->\n2:A->",
			.cmpf = strcmp,
			.item = "A",
			.arr = {{.item = "A", .left = -1, .right = 1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
		},
		{
			.desc = "Only Root node - Right Null",
			.expected = "0:A->\n1:B->A->",
			.cmpf = strcmp,
			.item = "A",
			.arr = {{.item = "A", .left = 1, .right = -1}, {.item = "B", .left =
				-1, .right = -1}, g_null},
		},
		{
			.desc = "Tree length : 1",
			.expected = "0:A->\n1:B->C->\n2:A->",
			.item = "A",
			.cmpf = strcmp,
			.arr = {{.item = "A", .left = 1, .right = 2}, {.item = "B", .left =
				-1, .right = -1}, {.item = "C", .left = -1, .right = -1},
				g_null},
		},
		{
			.desc = "Number binary tree",
			.item = "0",
			.expected = "0:1->\n1:2->3->\n2:4->5->6->7->\n3:0->",
			.cmpf = strcmp,
			.arr = {{.item = "1", .left = 1, .right = 2}, {.item = "2",
				.left = 3, .right = 4}, {.item = "3", .left = 5, .right = 6},
				{.item = "4", .left = -1, .right = -1}, {.item = "5", .left =
				-1, .right = -1}, {.item = "6", .left = -1, .right = -1},
				{.item = "7", .left = -1, .right = -1}, g_null},
		},
		{
			.desc = "Nmber tree - incomplite tree",
			.item = "0",
			.expected = "0:1->\n1:2->\n2:3->\n3:4->5->\n4:0->6->7->",
			.cmpf = strcmp,
			.arr = {{.item = "1", .left = 1, .right = -1}, {.item = "2",
				.left = 2, .right = -1}, {.item = "3", .left = 3, .right = 4},
				{.item = "4", .left = -1, .right = 5}, {.item = "5", .left = 6,
				.right = -1}, {.item = "6", .left = -1, .right = -1},
				{.item = "7", .left = -1, .right = -1}, g_null},
		},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex04/btree_insert_data", tests, is_test_passed, size,
		sizeof(tests[0]));
}
