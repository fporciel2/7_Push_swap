/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_correct_position.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:38:42 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/15 11:20:37 by fporciel         ###   ########.fr       */
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
 * This function is meant to check, for each element in the input list, its
 * correct position in the sorted list, by assigning the value representing the
 * correct element's position to the 'correct_position' value of each node.
*/

#include "push_swap.h"

/*
 * The ps_count_elements nested block is meant to count the number of elements
 * minor than the current value and to return that number, plus one, i.e. the
 * exact position's numeric representation that the element represented by the
 * value should have if the list is sorted.
 * It takes the value currently analyzed and the pointer to the head of the list
 * as parameters, then it sets to -1 the value of a iterator variable used to
 * take count of all the elements minor than the currently analyzed value by
 * sliding the list and incrementing that variable by 1 at each node that is
 * represented by a value minor than the currently analyzed one. Then, it
 * returns the so-calculated position by adding 1 to the resulting value.
 */
static int	ps_count_elements(int value, t_stack *head)
{
	ssize_t	minor;

	minor = -1;
	while (head != NULL)
	{
		if (head->value < value)
			minor++;
		head = head->next;
	}
	return (minor + 1);
}

/*
 * The function takes the main pointer as a parameter, and uses it to access the
 * temporary pointer to which the pointer to the head of the list is assigned. 
 * Then, it uses this temporary pointer to slide the list and assign to each
 * node's corresponding variable the value that represents the correct position
 * for that node, retrieved by the ps_count_elements function. 
 * The function does not return.
 */
void	ps_check_correct_position(t_ps *ps)
{
	ps->tmp = ps->a;
	while (ps->tmp != NULL)
	{
		ps->tmp->correct_position = ps_count_elements(ps->tmp->value, ps->a);
		ps->tmp = ps->tmp->next;
	}
}
