/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate_stack.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:34:02 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/16 10:24:55 by fporciel         ###   ########.fr       */
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
 * The reverse rotate move's class of functions is meant to implement the
 * respective three moves: 'rra', 'rrb' and 'rrr', i.e. reverse rotate stack_a,
 * reverse rotate stack_b and reverse rotate both stack_a and stack_b. So, these
 * functions execute the move and attempt to print them according to the
 * push_swap's syntax.
 */
#include "push_swap.h"

/*
 * The ps_reverse_rotate_a function is meant to put the down of the stack_a to
 * the top.
 * It checks whether the stack has at least two elements, avoiding illegal
 * memory accesses: if it have them, it performs the operation; in any case, it
 * tries to print the syntactically correct name of operation to the standard
 * output, and stops the program using ps_error if 'write' fails.
 * The operation is performed by using the 'tail' pointer to point the bottom of
 * the stack sliding the list from the head to the penultimate element and using
 * a temporary 'head' pointer to point the last element, then by assigning the
 * address of the top of the stack to the pointer to the last element's next
 * element, then by assigning the address of the end of list to the pointer to
 * the penultimate element's next element, and finally by assigning the address
 * to the new head to the pointer to the head of the list.
 */
void	ps_revrotate_a(t_ps *ps)
{
	t_stack	*head;
	t_stack	*tail;

	if (ps->a && ps->a->next)
	{
		tail = ps->a;
		while (tail->next->next != NULL)
			tail = tail->next;
		head = tail->next;
		head->next = ps->a;
		tail->next = NULL;
		ps->a = head;
	}
	if (write(1, "rra\n", 4) < 0)
		ps_error(ps);
	(ps->nummoves)++;
}

/*
 * The ps_reverse_rotate_b function is meant to put the down of the stack_b to
 * the top.
 * It checks whether the stack has at least two elements, avoiding illegal
 * memory accesses: if it have them, it performs the operation; in any case, it
 * tries to print the syntactically correct name of operation to the standard
 * output, and stops the program using ps_error if 'write' fails.
 * The operation is performed by using the 'tail' pointer to point the bottom of
 * the stack sliding the list from the head to the penultimate element and using
 * a temporary 'head' pointer to point the last element, then by assigning the
 * address of the top of the stack to the pointer to the last element's next
 * element, then by assigning the address of the end of list to the pointer to
 * the penultimate element's next element, and finally by assigning the address
 * to the new head to the pointer to the head of the list.
 */
void	ps_revrotate_b(t_ps *ps)
{
	t_stack	*head;
	t_stack	*tail;

	if (ps->b && ps->b->next)
	{
		tail = ps->b;
		while (tail->next->next != NULL)
			tail = tail->next;
		head = tail->next;
		head->next = ps->b;
		tail->next = NULL;
		ps->b = head;
	}
	if (write(1, "rrb\n", 4) < 0)
		ps_error(ps);
	(ps->nummoves)++;
}

/*
 * The ps_reverse_rotate_r function is meant to put the down of both the stacks 
 * to the respective top.
 * It does it, for each stack, as follows.
 * It checks whether the stack has at least two elements, avoiding illegal
 * memory accesses: if it have them, it performs the operation.
 * The operation is performed by using the 'tail' pointer to point the bottom of
 * the stack sliding the list from the head to the penultimate element and using
 * a temporary 'head' pointer to point the last element, then by assigning the
 * address of the top of the stack to the pointer to the last element's next
 * element, then by assigning the address of the end of list to the pointer to
 * the penultimate element's next element, and finally by assigning the address
 * to the new head to the pointer to the head of the list. In any case, the
 * function tries to print the syntactically correct name of operation to the 
 * standard output, and stops the program using ps_error if 'write' fails.
 */
void	ps_revrotate_r(t_ps *ps)
{
	t_stack	*head;
	t_stack	*tail;

	if (ps->a && ps->a->next)
	{
		tail = ps->a;
		while (tail->next->next != NULL)
			tail = tail->next;
		head = tail->next;
		head->next = ps->a;
		tail->next = NULL;
		ps->a = head;
	}
	if (ps->b && ps->b->next)
	{
		tail = ps->b;
		while (tail->next->next != NULL)
			tail = tail->next;
		head = tail->next;
		head->next = ps->b;
		tail->next = NULL;
		ps->b = head;
	}
	if ((write(1, "rrr\n", 4) < 0) && (ps->nummoves)++)
		ps_error(ps);
}
