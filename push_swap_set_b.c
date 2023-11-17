/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:12:14 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/17 15:00:29 by fporciel         ###   ########.fr       */
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

static int	ps_count_elements(int value, t_stack *head)
{
	ssize_t	bigger;

	bigger = -1;
	while (head != NULL)
	{
		if (head->value > value)
			bigger++;
		head = head->next;
	}
	return (bigger + 1);
}

static void	ps_correct_posit(t_ps *ps)
{
	ps->tmp = ps->b;
	while (ps->tmp != NULL)
	{
		ps->tmp->correct_position = ps_count_elements(ps->tmp->value, ps->b);
		ps->tmp = ps->tmp->next;
	}
}

static void	ps_positioning(t_ps *ps)
{
	t_stack	*tmp;
	int		position;

	tmp = ps->b;
	position = 0;
	while (tmp != NULL)
	{
		tmp->position = position;
		position++;
		tmp = tmp->next;
	}
}

void	ps_set_b(t_ps *ps)
{
	t_stack	*top;
	int		stacksize;
	int		fromwhere;

	top = ps->b;
	stacksize = ps_stacksize(ps->b);
	top->position = 0;
	ps_correct_posit(ps);
	if ((int)(top->correct_position) <= (stacksize / 2))
		fromwhere = 1;
	else
		fromwhere = 0;
	ps_positioning(ps);
	while (top->position != top->correct_position)
	{
		if (fromwhere == 1)
			ps_revrotate_b(ps);
		else
			ps_rotate_b(ps);
		ps_positioning(ps);
	}
}
