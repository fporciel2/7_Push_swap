/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:01:45 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/11 10:19:38 by fporciel         ###   ########.fr       */
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

void	ps_rotate_a(t_ps *ps)
{
	t_stack	*tmps;
	t_stack	*tmpl;

	if (ps->a && ps->a->next)
	{
		tmps = ps->a;
		tmpl = ps->a;
		while (tmpl->next != NULL)
			tmpl = tmpl->next;
		tmpl->next = tmps;
		ps->a = tmps->next;
		tmps->next = NULL;
	}
	if (write(1, "ra\n", 3) < 0)
		ps_error(ps);
}

void	ps_rotate_b(t_ps *ps)
{
	t_stack	*tmps;
	t_stack	*tmpl;

	if (ps->b && ps->b->next)
	{
		tmps = ps->b;
		tmpl = ps->b;
		while (tmpl->next != NULL)
			tmpl = tmpl->next;
		tmpl->next = tmps;
		ps->b = tmps->next;
		tmps->next = NULL;
	}
	if (write(1, "rb\n", 3) < 0)
		ps_error(ps);
}

void	ps_rotate_r(t_ps *ps)
{
	t_stack	*tmps;
	t_stack	*tmpl;

	if (ps->a && ps->a->next)
	{
		tmps = ps->a;
		tmpl = ps->a;
		while (tmpl->next != NULL)
			tmpl = tmpl->next;
		tmpl->next = tmps;
		ps->a = tmps->next;
		tmps->next = NULL;
	}
	if (ps->b && ps->b->next)
	{
		tmps = ps->b;
		tmpl = ps->b;
		while (tmpl->next != NULL)
			tmpl = tmpl->next;
		tmpl->next = tmps;
		ps->b = tmps->next;
		tmps->next = NULL;
	}
	if (write(1, "rr\n", 3) < 0)
		ps_error(ps);
}
