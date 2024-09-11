/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 00:37:37 by mmoulati         ###   ########.fr       */
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
	char			**datas;
	int				expected;
}					t_request;

int					ft_list_size(t_list *begin_list);

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head;
	t_list		*tmp;
	int			i;

	init_response(&res, req->desc);
	i = 0;
	head = 0;
	if (req->datas)
	{
		while (req->datas[i])
		{
			tmp = head;
			head = ft_create_elem(req->datas[i]);
			head->next = tmp;
			i++;
		}
	}

	sprintf(res.result, "%d", ft_list_size(head));
	sprintf(res.expected, "%d", req->expected);
	if (strcmp(res.expected, res.result) == 0)
		res.is_pass = 1;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (res);
}

void	test_list_size(void)
{
	int		size;
	char	*case_1[] = {"A", NULL};
	char	*case_2[] = {"A", "B", NULL};
	char	*case_3[] = {"A", "B", "C", NULL};

	t_request tests[] = {
		{.desc = "Empty List", .expected = 0, .datas = NULL},
		{.desc = "One element List", .expected = 1,.datas = case_1},
		{.desc = "Two element List", .expected = 2,.datas = case_2},
		{.desc = "Three element list",.expected = 3,.datas = case_3}
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex02/ft_list_size", tests, is_test_passed, size,
		sizeof(tests[0]));
}
