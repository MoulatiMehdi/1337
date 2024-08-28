/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_valid_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:31:18 by mehdi             #+#    #+#             */
/*   Updated: 2024/08/26 18:58:20 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/utils.h"

typedef struct s_test
{
	int				expected;
	char			*expected_output;
	char			*input;
	char			*desc;

}					t_test;

int					is_valid_unit(char *str);

static t_response	is_funct_pass(void *data)
{
	t_response	response;
	t_test		test_func;
	int			res;

	test_func = *((t_test *)data);
	res = is_valid_unit(test_func.input);
	response.is_pass = res == test_func.expected;
	response.desc = test_func.desc;
	lltoa(res, response.result, 22);
	lltoa(test_func.expected, response.expected, 22);
	return (response);
}

void	test_is_valid_num(void)
{
	int				size;
	unsigned long	elem_size;

	t_test tests[] = {
		{.expected = 0, .desc = "Should Fail : 'Kib'", .input = "Kib"},
		{.expected = 0, .desc = "Should Fail : 'KIB'", .input = "KIB"},
		{.expected = 0, .desc = "Unknown Unit", .input = "LiB"},
		{.expected = 0, .desc = "Unit start with a space", .input = " kiB"},
		{.expected = 0, .desc = "Unit start and end with a space",
			.input = " kiB"},
		{.expected = 0, .desc = "Unit ends with a space", .input = " kiB"},
		{.expected = 1, .desc = "long kilobytes with uppcase", .input = "KiB"},
		{.expected = 1, .desc = "long kilobytes with lowercase",
			.input = "kiB"},
		{.expected = 1, .desc = "Empty string", .input = ""},
		{.expected = 1, .desc = "bit with lowercase", .input = "b"},
		{.expected = 1, .desc = "bit with uppercase", .input = "B"},
		{.expected = 1, .desc = "kilobytes with uppercase", .input = "K"},
		{.expected = 1, .desc = "kilobytes with lowercase", .input = "k"},
		{.expected = 1, .desc = "kilobits with lowercase", .input = "kB"},
		{.expected = 1, .desc = "kilobits with uppercase", .input = "KB"},
		{.expected = 0, .desc = "kilobits with lowercase 'b'", .input = "Kb"},
	};
	size = sizeof(tests) / sizeof(tests[0]);
	elem_size = sizeof(tests[0]);
	run_test("is_valid_unit", tests, is_funct_pass, size, elem_size);
}
