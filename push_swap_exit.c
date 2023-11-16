/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:58:27 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/16 11:11:00 by fporciel         ###   ########.fr       */
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

/*
 * The push_swap_exit.c file contains three functions:
 * 1 - ps_clean, that frees memory allocated for a stack;
 * 2 - ps_success, that frees memory using ps_clean if needed and then stops
 * the program successfully;
 * 3 - ps_error, that frees memory using ps_clean if needed and then stops the
 * program after printing an error message on the standard error.
 * All these functions are exposed to be called when needed.
 * None of these functions return a value.
 */
/*
 * *****ps_clean*****
 * The function takes a pointer to the head of the linked list that represents
 * a stack, that could be stack_a or stack_b depending on the circumstances. I
 * then declares another pointer of the same type in order to easily swap
 * between elements of the linked list. If the head's pointer is not NULL, i.e.
 * if it is possible to access the linked list and free the memory allocated to
 * build it, it uses the automatic variable declared before to point the memory
 * region to free, and the parameter to slide the linked list until there is
 * nothing more to free.
 */
void	ps_clean(t_stack *head)
{
	t_stack	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/*
 * *****ps_success*****
 * The function takes the main push_swap's variable as a parameter and
 * dereferences it to the heads of stacks, stack_a and stack_b, in order to
 * check in order to check whether there is a need to free the memory. 
 * If it is present for at least one of the two stacks, it frees the memory 
 * appropriately using 'ps_clean', - otherwise it does not: in both cases, 
 * it interrupts the execution of the program using 'exit' successfully.
 */
void	ps_success(t_ps *ps)
{
	if ((ps->a == NULL) && (ps->b == NULL))
		exit(EXIT_SUCCESS);
	if (ps->a != NULL)
		ps_clean(ps->a);
	if (ps->b != NULL)
		ps_clean(ps->b);
	if (ps->k != NULL)
		ps_clean(ps->k);
	exit(EXIT_SUCCESS);
}

/*
 * ****ps_error****
 * Like 'ps_success', this  function takes the main push_swap's variable as 
 * a parameter and dereferences it to the heads of stacks, stack_a and 
 * stack_b, in order to check in order to check whether there is a need to
 * free the memory. 
 * If it is present for at least one of the two stacks, it frees the memory 
 * appropriately using 'ps_clean', - otherwise it does not: in both cases, 
 * it interrupts the execution of the program using 'exit', after writing an
 * error message on the standard error and then passing the output of the
 * corresponding 'write' call to the 'exit' function.
 */
void	ps_error(t_ps *ps)
{
	if ((ps->a == NULL) && (ps->b == NULL))
		exit(write(2, "Error\n", 6));
	if (ps->a != NULL)
		ps_clean(ps->a);
	if (ps->b != NULL)
		ps_clean(ps->b);
	if (ps->k != NULL)
		ps_clean(ps->k);
	exit(write(2, "Error\n", 6));
}
