/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 14:49:45 by mmoulati         ###   ########.fr       */
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
	void			*data;
	char			*expected;
	t_list			**head;

	char			**list;
}					t_request;
void				ft_list_push_front(t_list **begin_list, void *data);

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list *p;
	t_list *tmp;
	
	init_response(&res, req->desc);
	ft_list_push_front(req->head, req->data);
	ft_list_tostring(res.result, req->head);
	strcpy(res.expected, req->expected);
	if (strcmp(res.result, res.expected) == 0)
		res.is_pass = 1;
	p = 0;
	if (req->head)
		p = *req->head;
	if(p) 
		while(p)
		{
			tmp = p->next;
			free(p);
			p = tmp;
		}
	return (res);
}

void	test_push_front(void)
{
	int		size;
	t_list	*p_null;
	t_list	*head;

	p_null = NULL;
	head = ft_create_elem("A");
	t_request tests[] = {
		{.desc = "Head Reference is Null", .data = "Z",.head = NULL, .expected = "Null"},
		{.desc = "Head Value is Null", .data = "Z",.head = &p_null, .expected = "Z -> Null"},
		{
			.desc = "Head contains items",
			.data = NULL,
			.head = &head,
			.expected = "NULL -> A -> Null",
		}
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex01/ft_list_push_front", tests, is_test_passed, size,
		sizeof(tests[0]));
}
