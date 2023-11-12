/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:25:30 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/12 11:00:42 by fporciel         ###   ########.fr       */
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
 * The main Push_swap's function starts the program by taking the input list of
 * numbers as a parameter, and storing it in an array of arrays, someway pointed
 * by the 'argv' variable. It also takes into account the number of elements in
 * the list, using the parameter stored in the 'argc' variable. The
 * above-mentioned process is handled by the operating system: it loads the
 * push_swap program into memory and passes the command-line arguments to it as
 * an array of strings. 'argv' is an array of character pointers (pointing to
 * the respective strings) that contains these arguments. The first element,
 * 'argv[0]', is the name of the program, i.e., in this case, "./push_swap".
 * Subsequent elements, 'argv[1]', 'argv[2]', etc., contain the provided
 * arguments. 'argc' is an integer that stores the number of elements in the
 * 'argv' array: since the program name is counted, it is at least 1.
 * The 'argv' array is terminated with a 'NULL' pointer to indicate the end of
 * the argument list.
 *
 * One static variable is declared: 'ps'. You can see the definition of its
 * type, 't_ps', in the "push_swap.h" file. The choice of static storage class
 * depends on the convenience of automatic initialisation and the design choice
 * of relating all operations to the programme's memory space.
 *
 * Since at least one input is required by the program to show the correct
 * sorting algorithm, the 'main' function calls the 'ps_error' function, that
 * stops the program and provides error message on the standard error, if the
 * only string stored in 'argv' is the name of the program, i.e. if 'argc' is
 * equal to 1.
 *
 * After the first check, there's no need to access the pointer to the beginning
 * of the program's name, nor to take it into account when considering the
 * number of elements stored by 'argv'. So, the 'argv' pointer is incremented by
 * one arithmetic unit to point the first useful pointer, and 'argc''s value is
 * decreased to store the exact value of the number of arguments passed to the
 * program.
 *
 * 'argc', 'argv' and the address of 'ps' are then passed to the
 * 'ps_stack_generator' function, that parses the input and, if no errors 
 * occurr, the input is not already sorted and it is correct, changes the 'ps'
 * variable in order to allow the use of a heap-allocated stack data structure,
 * called stack_a, that is implemented as a linked list and has the same order
 * of values of the input list.
 *
 * In the end, the 'ps_success' function, that frees memory and stops the
 * program. push_swap shouldn't return anything. 
 */

int	main(int argc, char **argv)
{
	static t_ps	ps;
	t_stack		*tmp;

	if (argc == 1)
		ps_error(&ps);
	argv++;
	argc--;
	ps_stack_generator(argv, &ps);
	ps_check_correct_position(&ps);
	ps_introsort(&ps);
	ps_success(&ps);
	return (1);
}
