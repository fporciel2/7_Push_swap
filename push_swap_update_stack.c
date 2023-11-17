/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_update_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:48:49 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/17 10:40:02 by fporciel         ###   ########.fr       */
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

static void	ps_update_total(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->a;
	while (tmp != NULL)
	{
		tmp->total = tmp->distance + tmp->priority + tmp->position;
		tmp = tmp->next;
	}
}

static void	ps_flagzero(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->a;
	while (tmp != NULL)
	{
		tmp->priority_flag = 0;
		tmp = tmp->next;
	}
}

static void	ps_update_priority(t_ps *ps, int stacksize)
{
	t_stack		*tmp;
	t_stack		*to_prioritize;
	long long	priority;
	size_t		count;

	priority = 1;
	count = 0;
	ps_flagzero(ps);
	while (stacksize > 0)
	{
		tmp = ps->a;
		while (tmp != NULL)
		{
			if ((count == 0)
					|| ((tmp->correct_position > to_prioritize->correct_position)
						&& (tmp->priority_flag == 0)))
				to_prioritize = tmp;
			tmp = tmp->next;
		}
		to_prioritize->priority = priority;
		to_prioritize->priority_flag = 1;
		stacksize--;
		priority++;
	}
}

static void	ps_update_distance(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->a;
	while (tmp != NULL)
	{
		if (tmp->correct_position > tmp->position)
			tmp->distance = tmp->correct_position - tmp->position;
		else if (tmp->position > tmp->correct_position)
			tmp->distance = tmp->position - tmp->correct_position;
		else
			tmp->distance = 0;
		tmp = tmp->next;
	}
}

void	ps_update_stack(t_ps *ps, int stacksize)
{
	t_stack	*tmp;

	tmp = ps->a;
	ps_update_distance(ps);
	ps_update_priority(ps, stacksize);
	ps_update_total(ps);
	ft_printf("\n\n");
	while (tmp != NULL)
	{
		ft_printf("%d: p=%d, cp=%d, d=%d, pr=%d, t=%d\n",
				tmp->value, tmp->position, tmp->correct_position,
				tmp->distance, tmp->priority, tmp->total);
		tmp = tmp->next;
	}
	ft_printf("\n\n");
}
