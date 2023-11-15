/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:48:20 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/15 13:07:28 by fporciel         ###   ########.fr       */
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

static void	ps_continue_sort_three(t_ps *ps)
{
	if (ps_ismin(ps, ps->a->value) && ps_ismax(ps, ps->a->next->value))
	{
		ps_swap_a(ps);
		ps_rotate_a(ps);
	}
	else
		ps_revrotate_a(ps);
}

void	ps_sort_three(t_ps *ps)
{
	if (ps_ismin(ps, ps->a->next->value) && ps_ismax(ps, ps->a->next->next->value))
		ps_swap_a(ps);
	else if (ps_ismax(ps, ps->a->value) && ps_ismin(ps, ps->a->next->next->value))
	{
		ps_swap_a(ps);
		ps_revrotate_a(ps);
	}
	else if (ps_ismax(ps, ps->a->value) && ps_ismin(ps, ps->a->next->value))
		ps_rotate_a(ps);
	else
		ps_continue_sort_three(ps);
}
