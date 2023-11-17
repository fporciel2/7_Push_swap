/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_intelsort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:50:43 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/17 14:43:41 by fporciel         ###   ########.fr       */
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

static void	ps_label(t_ps *ps)
{
	t_stack	*tmp;
	ssize_t	position;

	tmp = ps->a;
	position = 0;
	while (tmp != NULL)
	{
		tmp->position = position;
		position++;
		tmp = tmp->next;
	}
}

/*static void	ps_adjust_stacks(t_ps *ps)
{
	if (((ps->a) && (ps->a->next) && (ps->a->value > ps->a->next->value))
			&& ((ps->b) && (ps->b->next) && (ps->b->value < ps->b->next->value)))
		ps_swap_s(ps);
	else if ((ps->a) && (ps->a->next) && (ps->a->value > ps->a->next->value))
		ps_swap_a(ps);
	else if ((ps->b) && (ps->b->next) && (ps->b->value < ps->b->next->value))
		ps_swap_b(ps);
}
*/
void	ps_intelsort(t_ps *ps)
{
	while (ps->a)
	{
		ps_label(ps);
		ps_check_correct_position(ps);
		ps_update_stack(ps, ps_stacksize(ps->a));
		ps_push_element(ps);
		ps_set_b(ps);
	}
	ps_fill_stack(ps);
}
