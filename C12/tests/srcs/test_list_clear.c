/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 15:20:04 by mmoulati         ###   ########.fr       */
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
	void			(*fct_free)(void *);
	int				size;
}					t_request;

void				ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

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
	head = 0;
	if (req->strs)
	{
		while (i < req->size)
		{
			tmp = head;
			head = ft_create_elem(req->strs[i]);
			head->next = tmp;
			i++;
		}
	}
	ft_list_clear(head, req->fct_free);
	res.is_pass = 1;
	tmp = head;
	if (size != 0)
	{
		res.is_pass = 0;
		sprintf(res.result, "size : %d", size);
		sprintf(res.expected, "size : %d", 0);
	}
	return (res);
}

void	test_list_clear(void)
{
	int		size;
	char	*case_0[] = {NULL};
	char	*case_1[] = {"A"};
	char	*case_2[] = {"A", "B"};
	char	*case_3[] = {"A", "B", "C", NULL};
	char	*case_4[] = {NULL, NULL, NULL, NULL};

	t_request tests[] = {
		{.desc = "Null array", .fct_free = 0, .strs = NULL, .size = 0},
		{.desc = "One Null Item", .fct_free = 0, .strs = case_0, .size = 1},
		{.desc = "One Null Item With Null Free function", .fct_free = 0,
			.strs = case_0, .size = 1},
		{.desc = "One string item ", .fct_free = 0, .strs = case_1, .size = 1},
		{.desc = "Two string items ", .fct_free = 0, .strs = case_2, .size = 2},
		{.desc = "Four items with NULL at the end", .fct_free = 0,
			.strs = case_3, .size = 4},
		{.desc = "Four NULL items ", .fct_free = 0, .strs = case_4, .size = 4},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex06/ft_list_clear", tests, is_test_passed, size,
		sizeof(tests[0]));
}
