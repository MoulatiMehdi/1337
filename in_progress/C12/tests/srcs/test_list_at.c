/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 17:24:12 by mmoulati         ###   ########.fr       */
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
	char			*expected;
	int				index;
	int size ;
}					t_request;

t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head;
	t_list		*tmp;
	t_list		*target;
	int			i;

	init_response(&res, req->desc);
	i = 0;
	head = 0;
	target = 0;
	if (req->strs && req->size > 0)
	{
		while (i < req->size)
		{
			tmp = head;
			head = ft_create_elem(req->strs[i]);
			if (req->index ==req->size - i - 1)
				target = head;
			head->next = tmp;
			i++;
		}
	}
	tmp = ft_list_at(head, req->index);
	sprintf(res.result, "%s", tmp ? (char *)tmp->data : NULL);
	sprintf(res.expected, "%s", req->expected);
	if (target == tmp)
		res.is_pass = 1;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (res);
}

void	test_list_at(void)
{
	int			size;
	char		*case_1[] = {"A", NULL};
	char		*case_2[] = {"A", "B", NULL};
	char		*case_3[] = {"A", "B", "C", NULL};
	char		*case_4[] = {NULL, NULL, NULL, NULL};
	t_request	tests[] = {
		{.desc = "Empty List", .strs = NULL, .index = 1,.size=0},
		{.desc = "Out of Range", .strs = case_3, .index = 10,.size=4},
		{.desc = "Two element List", .strs = case_1, .index = 0,.size=2},
		{.desc = "Three element List", .strs = case_2, .index =3,.size=3},
		{.desc = "Four element list", .strs = case_3, .index = 1,.size=4},
		{.desc = "All items are Null", .strs = case_4, .index = 1,.size=4}
	};

	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex02/ft_list_at", tests, is_test_passed, size,
		sizeof(tests[0]));
}
