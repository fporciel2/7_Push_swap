/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:02:02 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/11 11:33:16 by fporciel         ###   ########.fr       */
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
 * The functions of the swap - or switch - class implement the swapping move of
 * the push_swap language and attempt to print them according to the push_swap's
 * syntax. Basically, the swap move to a stack switches the first element with
 * the second, i.e. the top with the element <<under>> the top.
 */
#include "push_swap.h"

/*
 * The ps_swap_a function performs the 'sa' operation by switching the first
 * element of the stack_a with its second element.
 * It starts by checking, obviously, if the stack_a has at least two elements.
 * If this is the case, it assigns the address of the second element to a
 * temporary automatic variable, called 'tmp', and then assigns the address of
 * its next element (that is the end of list if the stack has only two
 * elements) to the pointer to the second element; then assigns the address of
 * the head to the pointer to the new second element, and finally assigns the
 * address of the new first element to the pointer to the new head.
 */
void	ps_swap_a(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->a && ps->a->next)
	{
		tmp = ps->a->next;
		ps->a->next = tmp->next;
		tmp->next = ps->a;
		ps->a = tmp;
	}
	if (write(1, "sa\n", 3) < 0)
		ps_error(ps);
}

/*
 * The ps_swap_b function performs the 'sb' operation by switching the first
 * element of the stack_a with its second element.
 * It starts by checking, obviously, if the stack_b has at least two elements.
 * If this is the case, it assigns the address of the second element to a
 * temporary automatic variable, called 'tmp', and then assigns the address of
 * its next element (that is the end of list if the stack has only two
 * elements) to the pointer to the second element; then assigns the address of
 * the head to the pointer to the new second element, and finally assigns the
 * address of the new first element to the pointer to the new head.
 */
void	ps_swap_b(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->b && ps->b->next)
	{
		tmp = ps->b->next;
		ps->b->next = tmp->next;
		tmp->next = ps->b;
		ps->b = tmp;
	}
	if (write(1, "sb\n", 3) < 0)
		ps_error(ps);
}

/*
 * The ps_swap_s function performs the 'ss' operation by switching the first
 * element of each stack with its second element.
 * It starts by checking, obviously, if the stack has at least two elements.
 * If this is the case, it assigns the address of the second element to a
 * temporary automatic variable, called 'tmp', and then assigns the address of
 * its next element (that is the end of list if the stack has only two
 * elements) to the pointer to the second element; then assigns the address of
 * the head to the pointer to the new second element, and finally assigns the
 * address of the new first element to the pointer to the new head.
 */
void	ps_swap_s(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->a && ps->a->next)
	{
		tmp = ps->a->next;
		ps->a->next = tmp->next;
		tmp->next = ps->a;
		ps->a = tmp;
	}
	if (ps->b && ps->b->next)
	{
		tmp = ps->b->next;
		ps->b->next = tmp->next;
		tmp->next = ps->b;
		ps->b = tmp;
	}
	if (write(1, "ss\n", 3) < 0)
		ps_error(ps);
}
