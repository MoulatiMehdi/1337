/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 14:14:02 by mmoulati         ###   ########.fr       */
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
	char			**strs;
	int				expected;
	int				size;
}					t_request;

t_list				*ft_list_push_strs(int size, char **strs);

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head;
	t_list		*tmp;
	int			i;
	int			size;

	size = 0;
	i = 0;
	init_response(&res, req->desc);
	head = ft_list_push_strs(req->size, req->strs);
	res.is_pass = 1;
	tmp = head;
	while (i < req->size && tmp)
	{
		if (tmp->data != req->strs[req->size - i -1])
		{
			sprintf(res.result, "item(%d) : %s", i, (char *)tmp->data);
			sprintf(res.expected, "item(%d) : %s", i, req->strs[i]);
			res.is_pass = 0;
			break ;
		}
		size++;
		i++;
		tmp = tmp->next;
	}
	if (res.is_pass && size != req->expected)
	{
		res.is_pass = 0;
		sprintf(res.result, "size : %d", size);
		sprintf(res.expected, "size : %d", req->expected);
	}
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (res);
}

void	test_push_strs(void)
{
	int			size;
	char		*case_0[] = {NULL};
	char		*case_1[] = {"A"};
	char		*case_2[] = {"A", "B"};
	char		*case_3[] = {"A", "B", "C", NULL};
	char		*case_4[] = {NULL,NULL,NULL, NULL};
	t_request	tests[] = 
	{	
		{.desc = "Null array", .expected = 0,.strs = NULL, .size = 0}, 
		{.desc = "One Null Item", .expected = 1,.strs = case_0, .size = 1}, 
		{.desc = "One string item ", .expected = 1,.strs = case_1, .size = 1}, 
		{.desc = "Two string items ",.expected = 2, .strs = case_2, .size = 2},	
		{.desc = "Four items with NULL at the end", .expected = 4,.strs = case_3, .size = 4},
		{.desc = "Four NULL items ", .expected = 4,.strs = case_4, .size = 4},
		{.desc = "Convert 2 out of 4 array items", .expected = 2,.strs = case_4, .size = 2}
	};

	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex05/ft_list_push_strs", tests, is_test_passed, size, sizeof(tests[0]));
}
