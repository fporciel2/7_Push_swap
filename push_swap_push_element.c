/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:18:55 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/18 06:12:56 by fporciel         ###   ########.fr       */
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

static t_stack	*ps_check_element(t_stack *head)
{
	t_stack	*to_push;

	to_push = head;
	while (head != NULL)
	{
		if (head->total < to_push->total)
			to_push = head;
		head = head->next;
	}
	return (to_push);
}

static int	ps_fromwhere(t_stack *to_push, int stacksize)
{
	if ((int)(to_push->position) <= (stacksize / 2))
		return (0);
	else
		return (1);
}

/*static void	ps_byrotation(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->b;
	if (ps->b && ps->b->next)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (ps->b->value < tmp->value)
		{
			ps_rotate_r(ps);
			return ;
		}
	}
	ps_rotate_a(ps);
}

static void	ps_byreverse(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->b;
	if (ps->b && ps->b->next)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (ps->b->value < tmp->value)
		{
			ps_revrotate_r(ps);
			return ;
		}
	}
	ps_revrotate_a(ps);
}
*/
void	ps_push_element(t_ps *ps)
{
	t_stack	*to_push;
	int		stacksize;
	int		fromwhere;

	to_push = ps_check_element(ps->a);
	ps_set_b(ps, to_push);
	stacksize = ps_stacksize(ps->a);
	fromwhere = ps_fromwhere(to_push, stacksize);
	while (ps->a != to_push)
	{
		if (fromwhere == 0)
			ps_rotate_a(ps);
		else
			ps_revrotate_a(ps);
	}
	ps_push_in_b(ps);
}
