/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:02:02 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/10 16:15:16 by fporciel         ###   ########.fr       */
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

void	ps_swap_a(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->a && ps->a->next)
	{
		tmp = ps->a->next;
		ps->a->next = tmp->next;
		tmp->next = ps->a;
		ps->a = tmp;
	}
	if (write(1, "sa\n", 3) < 0)
		ps_error(ps);
}

void	ps_swap_b(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->b && ps->b->next)
	{
		tmp = ps->b->next;
		ps->b->next = tmp->next;
		tmp->next = ps->b;
		ps->b = tmp;
	}
	if (write(1, "sb\n", 3) < 0)
		ps_error(ps);
}

void	ps_swap_s(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->a && ps->a->next)
	{
		tmp = ps->a->next;
		ps->a->next = tmp->next;
		tmp->next = ps->a;
		ps->a = tmp;
	}
	if (ps->b && ps->b->next)
	{
		tmp = ps->b->next;
		ps->b->next = tmp->next;
		tmp->next = ps->b;
		ps->b = tmp;
	}
	if (write(1, "ss\n", 3) < 0)
		ps_error(ps);
}
