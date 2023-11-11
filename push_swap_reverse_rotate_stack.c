/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate_stack.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:34:02 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/11 12:26:57 by fporciel         ###   ########.fr       */
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

/*
 * The reverse rotate move's class of functions is meant to implement the
 * respective three moves: 'rra', 'rrb' and 'rrr', i.e. reverse rotate stack_a,
 * reverse rotate stack_b and reverse rotate both stack_a and stack_b. So, these
 * functions execute the move and attempt to print them according to the
 * push_swap's syntax.
 */
#include "push_swap.h"

void	ps_revrotate_a(t_ps *ps)
{
	t_stack	*head;
	t_stack	*tail;

	if (ps->a && ps->a->next)
	{
		tail = ps->a;
		while (tail->next->next != NULL)
			tail = tail->next;
		head = tail->next;
		head->next = ps->a;
		tail->next = NULL;
		ps->a = head;
	}
	if (write(1, "rra\n", 4) < 0)
		ps_error(ps);
}

void	ps_revrotate_b(t_ps *ps)
{
	t_stack	*head;
	t_stack	*tail;

	if (ps->b && ps->b->next)
	{
		tail = ps->b;
		while (tail->next->next != NULL)
			tail = tail->next;
		head = tail->next;
		head->next = ps->b;
		tail->next = NULL;
		ps->b = head;
	}
	if (write(1, "rrb\n", 4) < 0)
		ps_error(ps);
}

void	ps_revrotate_r(t_ps *ps)
{
	t_stack	*head;
	t_stack	*tail;

	if (ps->a && ps->a->next)
	{
		tail = ps->a;
		while (tail->next->next != NULL)
			tail = tail->next;
		head = tail->next;
		head->next = ps->a;
		tail->next = NULL;
		ps->a = head;
	}
	if (ps->b && ps->b->next)
	{
		tail = ps->b;
		while (tail->next->next != NULL)
			tail = tail->next;
		head = tail->next;
		head->next = ps->b;
		tail->next = NULL;
		ps->b = head;
	}
	if (write(1, "rrr\n", 4) < 0)
		ps_error(ps);
}
