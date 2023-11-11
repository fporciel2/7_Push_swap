/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:01:45 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/11 10:56:53 by fporciel         ###   ########.fr       */
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
* Here's the collection of functions that perform the rotate operations
* according to push_swap's language and print them according to its syntax.
*/

#include "push_swap.h"

/*
 * The 'ra' move's implementation starts by checking if the move is 
 * appliable to the stack by verifying if the stack has at least two elements.
 * If it is the case, uses two variables to point the first and the last node of the
 * stack_a by assigning the address of the head to both and slide the stack with
 * one of them. Then, the function assigns the address of the head to the 
 * variable that points the end of list, the address of the second node to the
 * variable that points the head of the list, and the end of the list to the
 * variable that points the new head, so that the top of the stack is now at the
 * bottom.
 * In any case, finally the function tries to print the name of the move, 'ra', 
 * on the standard output, and interrupts the program using ps_error if 'write' 
 * fails.
 */
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

/*
 * The 'rb' move's implementation starts by checking if the move is 
 * appliable to the stack by verifying if the stack has at least two elements.
 * If it is the case, uses two variables to point the first and the last node of the
 * stack_b by assigning the address of the head to both and slide the stack with
 * one of them. Then, the function assigns the address of the head to the 
 * variable that points the end of list, the address of the second node to the
 * variable that points the head of the list, and the end of the list to the
 * variable that points the new head, so that the top of the stack is now at the
 * bottom.
 * In any case, finally the function tries to print the name of the move, 'rb', 
 * on the standard output, and interrupts the program using ps_error if 'write' 
 * fails.
 */
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

/*
 * The 'rr' move's implementation starts by checking if the move is 
 * appliable to the stack by verifying if each stack has at least two elements.
 * If it is the case, uses two variables to point the first and the last node of the
 * stack by assigning the address of the head to both and slide the stack with
 * one of them. Then, the function assigns the address of the head to the 
 * variable that points the end of list, the address of the second node to the
 * variable that points the head of the list, and the end of the list to the
 * variable that points the new head, so that the top of the stack is now at the
 * bottom.
 * In any case, finally the function tries to print the name of the move, 'rr', 
 * on the standard output, and interrupts the program using ps_error if 'write' 
 * fails.
 */
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
