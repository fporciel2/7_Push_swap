/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mechanical_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:20:55 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/15 15:02:37 by fporciel         ###   ########.fr       */
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

static int	ps_stacksize_a(t_ps *ps)
{
	t_stack	*address;

	ps->i = 0;
	address = ps->a;
	ps->tmp = address;
	ps->index = ps->i;
	while (address != NULL)
	{
		if (address->value < ps->tmp->value)
		{
			ps->tmp = address;
			ps->index = ps->i;
		}
		address = address->next;
		(ps->i)++;
	}
	return (ps->i);
}

void	ps_mechanical_sort(t_ps *ps)
{
	int	prox;

	while (ps_stacksize_a(ps) > 3)
	{
		prox = ps->i / 2;
		while (ps->a != ps->tmp)
		{
			if (prox > ps->index)
				ps_rotate_a(ps);
			else
				ps_revrotate_a(ps);
		}
		ps_push_in_b(ps);
	}
	ps_microsort(ps);
	while (ps->b != NULL)
		ps_push_in_a(ps);
}
