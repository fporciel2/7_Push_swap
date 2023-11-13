/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calculate_depth_limit.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:28:03 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/13 10:53:35 by fporciel         ###   ########.fr       */
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
 * The ps_calculate_depth_limit is meant to calculate the depth limit for the
 * Introsort algorithm. The depth limit is the product between the constant
 * factor and the floored 2-based logarithm of the input size, and allows,
 * according to empirical researches, to give a limit to the execution of
 * Quicksort and switch to Heapsort at the correct moment.
 */
#include "push_swap.h"

/*
 * ps_floor_log continues the work of ps_log (see below). It calculates the
 * floor of the base-2 logarithm of the input size. It takes as parameters the
 * current status of bitwise analysis of the input size and the current status
 * of the calculation of the logarithm. The function checks if 'size' is greater
 * than or equal to powers of 2 (4, 2, 1), and if it is, it right shifts 'size'
 * by the corresponding power of 2 and increments 'l' by that power. The
 * function then returns 'l'.
 */
static int	ps_floor_log(int size, int l)
{
	if (n >= 1<<4)
	{
		n >>= 4;
		l += 4;
	}
	if (n >= 1<<2)
	{
		n >>= 2;
		l += 2;
	}
	if (n >= 1<<1)
		l += 1;
	return (l);
}

/*
 * ps_log starts calculating the floor of the base-2 logarithm of the input
 * size, by executing the first two steps of checking if the input size is
 * greater than some powers of 2 (16, 8) and then shifting 'size' by the
 * corresponding power of 2 and incrementing 'l' by that power.
 * The function returns the current status of 'size' and 'l'.
 */
static int	ps_log(int size)
{
	int	l;

	l = 0;
	if (size >= 1<<16)
	{
		n >>= 16;
		l += 16;
	}
	if (n >= 1<<8)
	{
		n >>= 8;
		l += 8;
	}
	return (ps_floor_log(size, l));
}

/*
 * The ps_calculate_depth_limit calculates the depth limit based on 'size' and
 * on the coefficient 'cf', that represent, respectively, the input size of
 * push_swap and the experimental constant factor. It does this by multiplying
 * the constant factor by the floored logarithm of the size.
 */
int	ps_calculate_depth_limit(int size, int cf)
{
	return (cf * ps_log(size));
}
