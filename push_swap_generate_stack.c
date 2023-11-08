/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_generate_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:40:08 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/08 15:58:32 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   
* Push_swap is a versatile sorting algorithm visualization tool. Designed as
*  a part of a programming challenge, they demonstrate the efficiency of
*  different sorting algorithms by visually displaying their operations.
*  The Push_swap and Checker programs are designed to work together for
*  sorting integers using a set of specific instructions while visualizing the
*  sorting process. Push_swap generates a sequence of instructions to sort a
*  list of numbers, and Checker verifies whether these instructions are valid
*  and successfully sort the list.
*  
*  Copyright (C) 2023  Federico Porciello
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "push_swap.h"

static size_t	ps_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (((str[len] != 43) && (str[len] != 45)
			&& ((str[len] < 48) || (str[len] > 57)))
		|| (((str[len] == 43) || (str[len] == 45))
			&& (str[len + 1] == 0)))
		return (12);
	len++;
	while (str[len])
	{
		if ((str[len] < 48) || (str[len] > 57))
			return (12);
		len++;
	}
	return (len);
}

static int	ps_isduplicate(long long atol, t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->a;
	while (tmp != NULL)
	{
		if (tmp->value == atol)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ps_generate_node(t_ps *ps, int atoi)
{
	if (ps->i == 0)
	{
		ps->a = (t_stack *)malloc(sizeof(t_stack));
		if (ps->a == NULL)
			return (0);
		ps->tmp = ps->a;
		ps->tmp->value = atoi;
		ps->tmp->position = ps->i;
		ps->tmp->next = NULL;
		return (1);
	}
	ps->tmp->next = (t_stack *)malloc(sizeof(t_stack));
	if (ps->tmp->next == NULL)
		return (0);
	ps->tmp = ps->tmp->next;
	ps->tmp->value = atoi;
	ps->tmp->position = ps->i;
	ps->tmp->next = NULL;
	return (1);
}

static int	ps_check_value(char *argvi, char **argv, int *flag, t_ps *ps)
{
	size_t		argvilen;
	long long	atol;
	int			atoi;

	argvilen = ps_strlen(argvi);
	if (argvilen > 11)
		return (0);
	atol = ft_atol(argvi);
	if ((atol > 2147483647) || (atol < -2147483648) || ps_isduplicate(atol, ps))
		return (0);
	atoi = ft_atoi(argvi);
	if ((argvi != argv[0]) && (ps->tmp->value > atoi))
		*flag = 0;
	return (ps_generate_node(ps, atoi));
}

void	ps_stack_generator(int stacksize, char **argv, t_ps *ps)
{
	int		flag;

	flag = 1;
	ps->i = 0;
	if (stacksize == 0)
		ps_error(ps);
	while (argv[ps->i] != NULL)
	{
		if (!ps_check_value(argv[ps->i], argv, &flag, ps))
			ps_error(ps);
		(ps->i)++;
	}
	if (flag == 1)
		ps_success(ps);
}
