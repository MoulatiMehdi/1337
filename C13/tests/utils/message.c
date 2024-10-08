/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@1337.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 01:41:50 by mmoulati          #+#    #+#             */
/*   Updated: 2024/09/16 01:42:04 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	msg_pass(char *str)
{
	printf("\t" GREEN CHECK GRAY "  %s" DEFAULT "\n", str);
}

void	msg_fail(char *desc, char *expected, char *result)
{
	printf("\t" RED CROSS GRAY " %s" DEFAULT "\n", desc);
	printf("\t\tExpected : '%s'\n", expected);
	printf("\t\tGot      : '%s'\n" DEFAULT, result);
}

void	msg_status(char *func_name, int errors)
{
	printf(errors ? FAIL : PASS);
	printf(" %s\n\n\n" DEFAULT, func_name);
}
