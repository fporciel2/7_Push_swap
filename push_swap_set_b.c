/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:12:14 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/18 06:57:39 by fporciel         ###   ########.fr       */
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

static t_stack	*ps_set_top(t_ps *ps, t_stack *tp)
{
	t_stack	*tmp;
	t_stack	*top;

	tmp = ps->b;
	while (tmp && (tmp->value > tp->value))
		tmp = tmp->next;
	if (tmp == NULL)
		return (NULL);
	top = tmp;
	while (tmp != NULL)
	{
		if ((tmp->value < tp->value) && (tmp->value > top->value))
			top = tmp;
		tmp = tmp->next;
	}
	return (top);
}

static int	ps_set_fromwhere(t_ps *ps, t_stack *top)
{
	int		stacksize;
	int		count;
	t_stack	*tmp;

	stacksize = ps_stacksize(ps->b);
	count = 0;
	tmp = ps->b;
	while (tmp != top)
	{
		count++;
		tmp = tmp->next;
	}
	if (count <= (stacksize / 2))
		return (0);
	return (1);
}

static void	ps_set_stack_b(t_ps *ps, t_stack *top, int fromwhere)
{
	if (top == NULL)
		return ;
	if (fromwhere == 0)
	{
		while (ps->b != top)
			ps_rotate_b(ps);
	}
	else
	{
		while (ps->b != top)
			ps_revrotate_b(ps);
	}
}

void	ps_set_b(t_ps *ps, t_stack *tp)
{
	t_stack	*top;

	top = ps_set_top(ps, tp);
	ps_set_stack_b(ps, top, ps_set_fromwhere(ps, top));
}
