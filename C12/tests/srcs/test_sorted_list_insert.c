/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sorted_list_insert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:19:01 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/12 17:30:32 by mmoulati         ###   ########.fr       */
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
	void * data;
	int (*cmp)();
	t_array			list1;
	char			*expected;
}					t_request;


void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());

static t_response	is_test_passed(t_request *req)
{
	t_response	res;
	t_list		*head;

	init_response(&res, req->desc);
	head = create_list(req->list1);
	ft_sorted_list_insert(req->list1.length == -1 ?NULL : &head,req->data,req->cmp);
	res.is_pass = 1;
	ft_list_tostring(res.result,&head);
	sprintf(res.expected,"%s",req->expected);
	if(strcmp(res.result,res.expected) != 0)
		res.is_pass = 0;
	clear_list(head);
	return (res);
}

void	test_sorted_list_insert(void)
{
	int			size;

	char *strs[][10] = {
		{"A"},
		{"A", "E"},
		{"A", "B", "C"},
		{"A", "B", "C", "D"},
		{"D", "D", "D", "D"},
		{"apple","banana","cherry","grape","kiwi","mango","orange","peach","strawberry","watermelon"},
		{"apple","cherry","grape","kiwi","mango","orange","peach","strawberry","watermelon"},
	};
	t_array cases[] = {
		{.strs=NULL,.length=-1},
		{.strs=NULL,0},
		{strs[0],1},
		{strs[1],2},
		{strs[2],3},
		{strs[3],4},
		{strs[4],4},
		{strs[5],10},
		{strs[6],9},
	};
	t_request tests[] = {
		{.desc = "Both Null list", .list1 = cases[0], .expected = "Null",.data="",.cmp=strcmp,},
		{.desc = "Empty List", .list1 = cases[1], .expected = "A -> Null",.data="A",.cmp=strcmp,},
		{.desc = "One Element - Add at the end ",  .list1 = cases[2], .expected = "A -> C -> Null",.data="C",.cmp=strcmp,},
		{.desc = "One Element - Add at the start",  .list1 = cases[2], .expected = "0 -> A -> Null",.data="0",.cmp=strcmp,},
		{.desc = "Two Element - add at the end", .list1 = cases[3], .expected = "A -> E -> Z -> Null",.data="Z",.cmp=strcmp,},
		{.desc = "Two Element - added at the start", .list1 = cases[3], .expected = "0 -> A -> E -> Null",.data="0",.cmp=strcmp,},
		{.desc = "Two Element - added at middle", .list1 = cases[3], .expected = "A -> B -> E -> Null",.data="B",.cmp=strcmp,},
		{.desc = "Three element - empty string", .list1 = cases[4], .expected = " -> A -> B -> C -> Null",.data="",.cmp=strcmp,},
		{.desc = "Three element - empty add at middle", .list1 = cases[4], .expected = "A -> B -> B -> C -> Null",.data="B",.cmp=strcmp,},
		{.desc = "Four element list - Add at start", .list1 = cases[5], .expected = "0 -> A -> B -> C -> D -> Null",.data="0",.cmp=strcmp,},
		{.desc = "Four Same list - Add at start", .list1 = cases[6], .expected = "0 -> D -> D -> D -> D -> Null",.data="0",.cmp=strcmp,},
		{.desc = "Four Same list - Add at end", .list1 = cases[6], .expected = "D -> D -> D -> D -> Z -> Null",.data="Z",.cmp=strcmp,},
		{.desc = "Four Same list - Same data", .list1 = cases[6], .expected = "D -> D -> D -> D -> D -> Null",.data="D",.cmp=strcmp,},
		{.desc = "10 Fruit list - Random", .list1 = cases[7], .expected = "apple -> banana -> cherry -> coconus -> grape -> kiwi -> mango -> orange -> peach -> strawberry -> watermelon -> Null",.data="coconus",.cmp=strcmp,},
		{.desc = "9 Fruit list - Random before the end", .list1 = cases[8], .expected = "apple -> cherry -> grape -> kiwi -> mango -> orange -> peach -> strawberry -> sziiz -> watermelon -> Null",.data="sziiz",.cmp=strcmp,},
		{.desc = "9 Fruit list - Random at the end", .list1 = cases[8], .expected = "apple -> cherry -> grape -> kiwi -> mango -> orange -> peach -> strawberry -> watermelon -> xxx -> Null",.data="xxx",.cmp=strcmp,},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	run_test("ex16/ft_sorted_list_insert", tests, is_test_passed, size,
		sizeof(tests[0]));
}
