/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:41:31 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/15 11:11:29 by fporciel         ###   ########.fr       */
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
 * According to the the push_swap's characteristics, the following header file
 * is meant to define the instances of its implicit library of functions,
 * avoiding, thanks to the 'ifndef-endif' block that blocks multiple definitions
 * and multiple inclusions of the same header, incorrect inclusions by the
 * program's source files. Here are defined structures and functions used by the
 * program.
 * See README.md for more details.
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./1_libft/libft.h"
# include "./2_ft_printf/ft_printf.h"

/*
 * The s_stack structure is the most important, because it is used to define and
 * implement the stack's type as a linked list that treats each element of the
 * stack as a node and the end of stack as a null end of list. Each node
 * contains three variables corresponding, respectively, to the value of the
 * element, to its position in the input list, and to the position that it
 * should have if the list is sorted.
 */
typedef struct s_stack
{
	int				value;
	size_t			position;
	size_t			correct_position;
	struct s_stack	*next;
}					t_stack;

/*
 * The s_op structure is meant to take a register of the number of times that
 * each operation must be executed in a certain phase of the program's run.
 * Values must be registered by increasing during analysis of complexity, and
 * decreased during execution of operations.
 */
typedef struct s_op
{
	size_t	pb;
	size_t	pa;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}			t_op;

/*
 * The main structure s_ps is meant to point the head of both the stacks, to
 * perform auxiliary and cross-functional operations, to take control over
 * analysis and execution of instructions. Generally, it is used to link all the
 * fields of memory used by the program.
 */
typedef struct s_ps
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*tmp;
	size_t		i;
	struct s_op	ops;
}				t_ps;

void	ps_stack_generator(char **argv, t_ps *ps);
void	ps_error(t_ps *ps);
void	ps_clean(t_stack *head);
void	ps_success(t_ps *ps);
void	ps_push_in_a(t_ps *ps);
void	ps_push_in_b(t_ps *ps);
void	ps_swap_a(t_ps *ps);
void	ps_swap_b(t_ps *ps);
void	ps_swap_s(t_ps *ps);
void	ps_rotate_a(t_ps *ps);
void	ps_rotate_b(t_ps *ps);
void	ps_rotate_r(t_ps *ps);
void	ps_revrotate_a(t_ps *ps);
void	ps_revrotate_b(t_ps *ps);
void	ps_revrotate_r(t_ps *ps);
void	ps_check_correct_position(t_ps *ps);

#endif
