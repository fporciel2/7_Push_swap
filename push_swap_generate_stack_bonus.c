/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_generate_stack_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:27:17 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/20 14:28:09 by fporciel         ###   ########.fr       */
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

#include "checker.h"

/*
 * The 'ps_stack_generator' function is meant to parse the input array of
 * strings pointed to by 'argv' in order to check whether the list of numbers
 * passed to the program is valid and, if it is, generate the linked list that
 * represents the stack by changing the 'ps->a' parameter to point its head.
 * It also uses the 'stacksize' parameter to make it easier.
 */
/*
 * In this nested block, the analyzed string pointed to by 'str' is an element 
 * of the push_swap input list.
 * Since numeric values allowed by push_swap are 32-bit integer values, i.e.
 * they must be >= than -2147483648 and <= than 2147483647, strings using more
 * than 11 characters cannot represent a valid numeric value: so the function 
 * returns a value that means that the string is not valid when invalid 
 * characters are found checking it. Invalid characters are not-digital ones
 * and, for the first character, not significant positive or negative. '+' and
 * '-' are also considered invalid characters if they are the only characters in
 * the string.
 * The 'len' variable, representing the length of the string, is used to
 * calculate it, but the function stops iteration on the string also if 'len'
 * becomes greater than 11, not only if the end of string is reached by the
 * check.
 */
static size_t	ps_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (((str[len] != 43) && (str[len] != 45)
			&& ((str[len] < 48) || (str[len] > 57)))
		|| (((str[len] == 43) || (str[len] == 45))
			&& (str[len + 1] == 0)))
		return (12);
	len++;
	while (str[len] && (len < 12))
	{
		if ((str[len] < 48) || (str[len] > 57))
			return (12);
		len++;
	}
	return (len);
}

/*
 * This nested block compares the value of 'atol', that is the value of the
 * string currently analyzed, against each value of any element previously
 * analyzed and stored into the stack. It uses a 'tmp' variable in order to
 * easily slide the linked list starting from the head retrieved by
 * dereferencing to the 'a' pointer the main 'ps' variable. Until a NULL pointer
 * is assigned to the 'tmp' variable, it continues comparison if no previous
 * value is equal to 'atol'.
 */
static int	ps_isduplicate(long long atol, t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->a;
	while (tmp != NULL)
	{
		if (tmp->value == atol)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
 * This function effectively adds a node to the linked list representing the
 * stack_a. It allocates the memory for the node and initializes some of its
 * values (see the "push_swap.h" header for more informations about its values).
 * It uses the temporary variable 'ps->tmp' and the iterative variable 'ps->i' 
 * pointed by the main pointer 'ps', in order to track the elements and updated
 * the list at the correct address. If 'ps->i' is 0, it means that the node to
 * be generated is the first, i.e. the head of the list or the top of stack_a.
 * It labels the position of the node and returns 0 if the allocation fails.
 */
static int	ps_generate_node(t_ps *ps, int atoi)
{
	if (ps->i == 0)
	{
		ps->a = (t_stack *)malloc(sizeof(t_stack));
		if (ps->a == NULL)
			return (0);
		ps->tmp = ps->a;
		ps->tmp->value = atoi;
		ps->tmp->position = ps->i;
		ps->tmp->next = NULL;
		return (1);
	}
	ps->tmp->next = (t_stack *)malloc(sizeof(t_stack));
	if (ps->tmp->next == NULL)
		return (0);
	ps->tmp = ps->tmp->next;
	ps->tmp->value = atoi;
	ps->tmp->position = ps->i;
	ps->tmp->next = NULL;
	return (1);
}

/*
 * This nested block is meant to parse the list in reference to a specific
 * element, that is the string pointed to by 'argvi'. Primarly it uses the
 * 'ps_strlen' function in order to check whether the string represents an
 * integer number in less than 12 characters, then whether the value represented
 * by the string is minor than the 32-bit INT_MAX, greater than the 32-bit
 * INT_MIN, and different from the values previously stored in stack_a: if any
 * of these conditions is not satisfied, then the the function returns 0.
 * Otherwise it returns the return value of 'ps_generate_node', i.e. the status
 * of the allocation and initialization of the node that represents the current
 * element, after converting its alphanumeric representation into an integer
 * value and after setting the '*flag' variable to track whether the list of
 * numbers is already sorted.
 */
static int	ps_check_value(char *argvi, char **argv, int *flag, t_ps *ps)
{
	long long	atol;
	int			atoi;

	if (ps_strlen(argvi) > 11)
		return (0);
	atol = ft_atol(argvi);
	if ((atol > 2147483647) || (atol < -2147483648) || ps_isduplicate(atol, ps))
		return (0);
	atoi = ft_atoi(argvi);
	if ((argvi != argv[0]) && (ps->tmp->value > atoi))
		*flag = 0;
	return (ps_generate_node(ps, atoi));
}

/*
 * This function iterates through the input array of strings pointed by 'argv'
 * by passing each string and some tracking parameters to the ps_check_value
 * function. If the string is not valid or the allocation of its node fails, or
 * if before is detected that no elements are stored in the list, then it stops
 * the program by calling the ps_error function. If the list is successfully
 * generated as the implementation of stack_a, without errors, then the
 * ps_stack_generator function checks, through the 'flag' variable, whether the
 * stack is already sorted: if it is, then it stops the program using the
 * ps_success function.
 */
void	psc_stack_generator(char **argv, t_ps *ps)
{
	int		flag;

	flag = 1;
	ps->i = 0;
	if (*argv == NULL)
		ps_error(ps);
	while (argv[ps->i] != NULL)
	{
		if (!ps_check_value(argv[ps->i], argv, &flag, ps))
			ps_error(ps);
		(ps->i)++;
	}
	if (flag == 1)
		psc_success(ps);
}
