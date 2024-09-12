/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 01:01:04 by mmoulati         ###   ########.fr       */
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
}					t_request;

t_list				*ft_list_last(t_list *begin_list);

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head;
	t_list		*tail;
	t_list		*tmp;
	t_list *last;
	int			i;

	init_response(&res, req->desc);
	i = 0;
	head = 0;
	tail = 0;
	if (req->datas)
	{
		head = tail;
		while (req->datas[i])
		{
			tmp = head;
			head = ft_create_elem(req->datas[i]);
			if (i == 0)
				tail = head;
			head->next = tmp;
			i++;
		}
	}
	last = ft_list_last(head);
	sprintf(res.result, "%s",last?(char*)last->data:"(nil)" );
	sprintf(res.expected, "%s", tail? (char*)tail : "(nil)");
	if (tail == last) 
		res.is_pass = 1;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (res);
}

void	test_list_last(void)
{
	int			size;
	char		*case_1[] = {"A", NULL};
	char		*case_2[] = { "B", "C", NULL};
	char		*case_3[] = {"A", "B", "C", NULL};
	t_request	tests[] = {
		{.desc = "Empty List",.datas = NULL}, 
		{.desc = "One item",.datas = case_1}, 
		{.desc = "Two Element", .datas = case_2}, 
		{.desc = "Three Element",.datas = case_3}};

	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex03/ft_list_last", tests, is_test_passed, size, sizeof(tests[0]));
}
