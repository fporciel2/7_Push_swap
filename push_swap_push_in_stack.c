/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_in_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:51:53 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/10 15:58:18 by fporciel         ###   ########.fr       */
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
 * The ps_push_in_b and ps_push_in_a functions perform, respectively, the pop
 * from stack_a and push in stack_b and the pop from stack_b and push in stack_a
 * operations, as defined by the push_swap language, and print the operation on
 * the standard output according to its syntax.
 */

#include "push_swap.h"

/*
 * If no elements are in stack_a, i.e. a NULL pointer has the place of the
 * pointer to stack_a's head, the operations is ineffective; otherwise, the top
 * of stack_a is popped from it and pushed to the top of stack_b. 
 * In both cases, the operation is printed on the standard output and, if
 * 'write' fails, the program is interrupted using ps_error.
 */
void	ps_push_in_b(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->a != NULL)
	{
		tmp = ps->a;
		ps->a = ps->a->next;
		tmp->next = ps->b;
		ps->b = tmp;
	}
	if (write(1, "pa\n", 3) < 0)
		ps_error(ps);
}

/*
 * If no elements are in stack_b, i.e. a NULL pointer has the place of the
 * pointer to stack_b's head, the operations is ineffective; otherwise, the top
 * of stack_b is popped from it and pushed to the top of stack_a. 
 * In both cases, the operation is printed on the standard output and, if
 * 'write' fails, the program is interrupted using ps_error.
 */
void	ps_push_in_a(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->b != NULL)
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		tmp->next = ps->a;
		ps->a = tmp;
	}
	if (write(1, "pb\n", 3) < 0)
		ps_error(ps);
}
