/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/11 14:15:45 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stdlib.h"
#include "string.h"
#include "utils.h"
#include "ft.h"

typedef struct s_request
{
	char	*desc;
	void	*data;

}			t_request;

static t_response	is_test_passed(t_request *req)
{
	t_list		*p;
	t_response	res;

	init_response(&res,req->desc);
	p = ft_create_elem(req->data);
	to_string(res.result, p);
	values_to_string(res.expected, req->data, NULL);
	if (p && !p->next && p->data == req->data)
		res.is_pass = 1;
	if (p)
		free(p);
	return (res);
}

void	test_create_elem(void)
{
	int	size;

	t_request tests[] = {
		{.desc = "Null Data", .data = NULL},
		{.desc = "String Data", .data = "Hello world"},
		{.desc = "Number Data", .data = &size},
		{.desc = "Structure Data", .data = tests},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex00/ft_create_elem", tests, is_test_passed, size, sizeof(tests[0]));
}
