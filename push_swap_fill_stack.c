/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fill_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:18:15 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/17 13:52:45 by fporciel         ###   ########.fr       */
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

static t_stack	*ps_select_greater(t_stack *head)
{
	t_stack	*to_push;
	size_t	position;

	to_push = head;
	position = 0;
	while (head != NULL)
	{
		head->position = position;
		if (head->value > to_push->value)
			to_push = head;
		position++;
		head = head->next;
	}
	return (to_push);
}

static t_stack	*ps_last_elem(t_ps *ps)
{
	t_stack	*last;

	last = ps->b;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

static void	ps_new_set(t_ps *ps, t_stack *to_push)
{
	int	stacksize;
	int	fromwhere;

	stacksize = ps_stacksize(ps->b);
	if ((int)(to_push->position) <= (stacksize / 2))
		fromwhere = 0;
	else
		fromwhere = 1;
	while (ps->b != to_push)
	{
		if (fromwhere == 0)
			ps_rotate_b(ps);
		else
			ps_revrotate_b(ps);
	}
	ps_push_in_a(ps);
}

void	ps_fill_stack(t_ps *ps)
{
	t_stack	*to_push;

	while (ps->b)
	{
		to_push = ps_select_greater(ps->b);
		if (ps->b == to_push)
			ps_push_in_a(ps);
		else if (ps->b->next == to_push)
		{
			ps_swap_b(ps);
			ps_push_in_a(ps);
		}
		else if (ps_last_elem(ps) == to_push)
		{
			ps_revrotate_b(ps);
			ps_push_in_a(ps);
		}
		else
			ps_new_set(ps, to_push);
	}
}
