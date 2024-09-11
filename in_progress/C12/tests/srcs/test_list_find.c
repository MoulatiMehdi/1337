/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 21:39:25 by mmoulati         ###   ########.fr       */
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
	int				size;
	int (*cmp)();
	void * data_ref;
}					t_request;

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*target ;
	t_list		*head;
	t_list		*tmp;
	int			i;
	
	init_response(&res, req->desc);
	i = 0;
	head = 0;
	tmp = 0;
	if (req->strs && req->size > 0)
	{
		while (i < req->size)
		{
			tmp = head;
			head = ft_create_elem(req->strs[i]);
			head->next = tmp;
			i++;
		}
	}
	i = 0;
	tmp = head;
	res.is_pass = 1;
	target = 0;
	while(tmp)
	{
		if(req->cmp(req->data_ref,tmp->data) == 0)
		{
			target = tmp;
			i++;
			break;
		}
		tmp = tmp->next;

	}
	tmp = ft_list_find(head,req->data_ref,req->cmp);
	if(tmp != target)
	{
		res.is_pass = 0;
		sprintf(res.result,"address: %p data : %s",tmp,tmp?(char*)tmp->data:"(null)");
		sprintf(res.expected,"address: %p data : %s",target,target ?(char*)target->data: "(null)");
	}

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (res);
}

void	test_list_find(void)
{
	int	size;

	char *cases[10][10] = {
		{"A" },
		{"A", "E"},
		{"A", "B", "D"},
		{"A", "B", "C", "E"},
	};
	t_request	tests[] = {
		{.desc = "Empty List", .strs = NULL, .size=0,.cmp=strcmp,.data_ref="A"},
		{.desc = "Compare function Null", .strs = NULL, .size=0,.cmp=NULL,.data_ref="A"},
		{.desc = "fct function Null", .strs = NULL, .size=0,.cmp=strcmp,.data_ref="A"},
		{.desc = "One Element", .strs = cases[0], .size=1,.cmp=strcmp,.data_ref="B"},
		{.desc = "Two element List", .strs = cases[1], .size=2,.cmp=strcmp,.data_ref="B"},
		{.desc = "Three element List", .strs = cases[2], .size=3,.cmp=strcmp,.data_ref="E"},
		{.desc = "Four element list", .strs = cases[3], .size=4,.cmp=strcmp,.data_ref="E"},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex10/ft_list_find", tests, is_test_passed, size,
		sizeof(tests[0]));
}
