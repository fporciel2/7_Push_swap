/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:12:14 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/17 15:41:13 by fporciel         ###   ########.fr       */
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

void	ps_set_b(t_ps *ps)
{
	t_stack	*tmp;
	int		count;
	int		stacksize;

	ps_positioning_b(ps);
	stacksize = ps_stacksize(ps->b);
	count = 0;
	ps_create_k(ps);
	while (count != stacksize)
	{
		tmp = ps_assign_right_k(ps);
		while (tmp->position != tmp->correct_position)
		{
			ps_demisorting(tmp, ps->b, stacksize);
			ps_positioning_b(ps);
		}
		count++;
	}
	ps_destroy_k(ps);
}
