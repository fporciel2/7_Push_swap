/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:15:01 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/14 15:33:16 by fporciel         ###   ########.fr       */
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
 * This file is a collection of utility functions fo push_swap.
 */
#include "push_swap.c"

/*
 * By doing a check, the ps_adjust_stacks function swaps the top of one or both
 * the stacks if:
 * 1 - the elements to swap exist;
 * 2 - they are coherently belonging to the partition in which they are;
 * 3 - they are in reversed order.
 * In any case, the function doesn't return.
 */
void	ps_adjust_stacks(t_ps *ps)
{
	if ((ps->a && ps->a->next && (ps->a->value > pivot)
				&& (ps->a->next->value > pivot)
				&& (ps->a->value > ps->next->value))
			&& (ps->b && ps->b->next && (ps->b->value < pivot)
				&& (ps->b->next->value < pivot)
				&& (ps->b->value < ps->next->value)))
		ps_swap_s(ps);
	else if (ps->b && ps->b->next && (ps->b->value < pivot)
			&& (ps->b->next->value < pivot)
			&& (ps->b->value < ps->next->value))
		ps_swap_b(ps);
	else if (ps->a && ps->a->next && (ps->a->value > pivot)
			&& (ps->a->next->value > pivot)
			&& (ps->a->value > ps->next->value))
		ps_swap_a(ps);
}
