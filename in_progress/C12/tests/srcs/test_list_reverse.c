/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 18:56:41 by mmoulati         ###   ########.fr       */
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
	int				size ;
}					t_request;

void				ft_list_reverse(t_list **begin_list);

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
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

	if(req->size < 0)
		ft_list_reverse(NULL);
	else
		ft_list_reverse(&head);
	i = 0;
	tmp = head;
	res.is_pass = 1;
	while(tmp)
	{
		if(i< req->size && tmp->data != req->strs[i])
		{
			res.is_pass = 0;
			sprintf(res.result,"item (%d) : %s", i, (char*)tmp->data);
			sprintf(res.expected,"item (%d) : %s", i, req->strs[i]);
			break;
		}
		tmp = tmp->next;
		i++;
	}
	if(res.is_pass == 1 && req->size != -1 && i != req->size)
	{
		res.is_pass = 0;
		sprintf(res.expected,"size : %d",req->size);
		sprintf(res.result,"size : %d",i);
	}
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (res);
}

void	test_list_reverse(void)
{
	int			size;

	char *cases[10][10] = {
		{"A" },
		{"A", "E"},
		{"A", "B", NULL},
		{"A", "B", "C", NULL},
		{NULL, NULL, NULL, NULL},
	};
	t_request	tests[] = {
		{.desc = "Null list", .strs = NULL, .size=-1},
		{.desc = "Empty List", .strs = NULL, .size=0},
		{.desc = "One Element", .strs = cases[0], .size=1},
		{.desc = "Two element List", .strs = cases[1], .size=2},
		{.desc = "Three element List", .strs = cases[2], .size=3},
		{.desc = "Four element list", .strs = cases[3], .size=4},
		{.desc = "All items are Null", .strs = cases[4], .size=4}
	};

	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex08/ft_list_reverse", tests, is_test_passed, size,
		sizeof(tests[0]));
}
