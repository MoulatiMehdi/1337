/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:53:30 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 20:33:36 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

typedef struct s_request
{
	char			*desc;
	void			*data_ref;
}					t_request;

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_btree		*root;

	root = btree_create_node(req->data_ref);
	init_response(&res, req->desc);
	if (root == 0)
	{
		strcpy(res.result, "node: Null");
		strcpy(res.expected, "node: Not Null");
	}
	else if (root->left)
	{
		strcpy(res.result, "node->Left : Not Null");
		strcpy(res.expected, "node->Left : Null");
	}
	else if (root->right)
	{
		strcpy(res.result, "node->Right : Not Null");
		strcpy(res.expected, "node->Right : Null");
	}
	else if (root->item != req->data_ref)
	{
		strcpy(res.result,
			"node->item : not the same address as item of the input");
		sprintf(res.expected, "item : %p", root->item);
	}
	else
		res.is_pass = 1;
	if (root)
		free(root);
	return (res);
}

void	test_create_node(void)
{
	int	size;

	t_request tests[] = {
		{.desc = "NULL Item", .data_ref = 0},
		{.desc = "String Item", .data_ref = "Test"},
		{.desc = "Int Item", .data_ref = &size},
		{.desc = "Structure Item", .data_ref = &tests[0]},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex00/btree_create_node", tests, is_test_passed, size,
		sizeof(tests[0]));
}
