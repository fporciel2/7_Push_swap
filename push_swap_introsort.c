/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_introsort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:05:38 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/14 15:11:51 by fporciel         ###   ########.fr       */
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
 * The ps_introsort function implements recursively the introsort algorithm. The
 * algorithm is a kind of quicksort, that switches elements recursively between 
 * the two stacks by partitioning them (see the ps_partition_a and 
 * ps_partition_b commits) until the depth limit of recursion is reached: when
 * it is reached, it switches sorting process to the ps_heapsort function, that
 * implements the heapsort algorithm, and also switches the process to the
 * ps_insertionsort function, that implements the insertionsort algorithm, if
 * the size of the current partition is greater or equal to 16.
 */
#include "push_swap.h"

/*
 * The ps_partition_b function is meant to apply the QuickSort's recursion to
 * the minor part of the stack to sort, so that the this partition can be
 * subpartitioned.
 * It takes the main pointer and the size of the current partition. Then, it
 * uses two variables, an integer and a pointer, to store respectively a pivot
 * value chase by parsing the stack with the ps_median_of_three function, and
 * the address of the head of the list representing the minor stack's partition.
 * Then, it slides all the partition and pushes in the other partition the
 * elements greater than the pivot, and at the bottom of the partition the
 * elements that are smaller. It uses also the ps_adjust_stacks utility to
 * micro-sort the elements in the stack.
 * Then, it calculates and returns the partition's size by increasing the value
 * of the variable used to store the partition's size at each node reached by
 * sliding the partition.
 */
static int	ps_partition_b(t_ps *ps, int size)
{
	int		pivot;
	t_stack	*tmp;

	pivot = ps_median_of_three(ps->b);
	tmp = ps->b;
	while (size > 0)
	{
		if (tmp->value > pivot)
			ps_push_in_a(ps);
		else
			ps_rotate_b(ps);
		ps_adjust_stacks(ps);
		size--;
	}
	size = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

/*
 * The ps_partition_a function is meant to apply the QuickSort's recursion to
 * the greater part of the stack to sort, so that the this partition can be
 * subpartitioned.
 * It takes the main pointer and the size of the current partition. Then, it
 * uses two variables, an integer and a pointer, to store respectively a pivot
 * value chase by parsing the stack with the ps_median_of_three function, and
 * the address of the head of the list representing the bigger stack's 
 * partition.
 * Then, it slides all the partition and pushes in the other partition the
 * elements smaller than the pivot, and at the bottom of the partition the
 * elements that are greater. It uses also the ps_adjust_stacks utility to
 * micro-sort the elements in the stack.
 * Then, it calculates and returns the partition's size by increasing the value
 * of the variable used to store the partition's size at each node reached by
 * sliding the partition.
 */
static int	ps_partition_a(t_ps *ps, int size)
{
	int		pivot;
	t_stack	*tmp;

	pivot = ps_median_of_three(ps->a);
	tmp = ps->a;
	while (size > 0)
	{
		if (tmp->value <= pivot)
			ps_push_in_b(ps);
		else
			ps_rotate_a(ps);
		ps_adjust_stacks(ps);
		size--;
	}
	size = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

/*
 * The ps_introsort function takes the main pointer, the input size to the
 * program, and the previously calculated depth limit as parameters. 
 * It then reserves memory for two integers, that will represent, respectively,
 * the size of the partitioning of stack_a and stack_b. At every iteration, the
 * ps_introsort function checks whether the input size parameter is minor or
 * equal than 16, because it can be such at first iteration, but more probably
 * because subsequent calls to ps_introsort will consider the input size as the
 * partitioning size and viceversa: if this is the case, it calls the
 * ps_insertionsort function to sort the stack or the partition. Then, it checks
 * the depth limit status. Since at any subsequent call of ps_introsort the
 * depth limit is decreased, an eccessive depth required by the quicksort
 * procedure (that is implicitly used by the Introsort algorithm) will cause the
 * function to conclude the sorting process using the ps_heapsort function, that
 * implements the heapsort algorithm.
 * After that check, the function calls the ps_partition_a and the 
 * ps_partition_b functions to fill, respectively, the memory areas defined by 
 * its two automatic variables: the first function splits the stack according to
 * a pivot detection and returns the number of elements smaller or equal to the
 * pivot (i.e. the modified stack_a size); the second one does exactly the 
 * contrary, by splitting stack_b according to an analogous pivot detection and 
 * returning the number of elements greater or equal than the pivot.
 * The above-mentioned partitioning is done according to the corrisponding input
 * parameter, that is 0 at the first call.
 * Finally, the function calls itself using, first, the 0 parameter, that
 * represents the partitioning of stack_a, and then the 1 parameter, that
 * represents the partitioning of stack_b.
 */
void	ps_introsort(t_ps *ps, int size, int dl, int param)
{
	int	part_a;
	int	part_b;

	if (size <= 16)
		ps_insertionsort();
	else if (dl == 0)
		ps_heapsort();
	else
	{
		if (param == 0)
			part_a = ps_partition_a(ps, size);
		else
			part_b = ps_partition_b(ps, size);
		ps_introsort(ps, part_a, (dl - 1), 0);
		ps_introsort(ps, part_b, (dl - 1), 1);
	}
}
