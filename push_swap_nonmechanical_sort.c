/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_nonmechanical_sort.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:36:04 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/16 12:13:06 by fporciel         ###   ########.fr       */
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
static void	ps_show_stack_k(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->k;
	ft_printf("\n\nSTACK K\n\n");
	while (tmp != NULL)
	{
		ft_printf("%d is at position %d with correct position %d\n",
				tmp->value, tmp->position, tmp->correct_position);
		tmp = tmp->next;
	}
	ft_printf("\n");
}*/

static void	ps_sort_stack_k(t_ps *ps)
{
	t_stack	*tmp;
	int		value;
	int		cp;

	while (!ps_issorted_k(ps))
	{
		tmp = ps->k;
		while (tmp != NULL)
		{
			if (tmp->position != tmp->correct_position)
			{
				ps->tmp = ps->k;
				while (ps->tmp->position != tmp->correct_position)
					ps->tmp = ps->tmp->next;
				value = tmp->value;
				cp = tmp->correct_position;
				tmp->value = ps->tmp->value;
				tmp->correct_position = ps->tmp->correct_position;
				ps->tmp->value = value;
				ps->tmp->correct_position = cp;
			}
			tmp = tmp->next;
		}
	}
}

static void	ps_continue_nonmechanical_sort(t_ps *ps, t_stack *tmp)
{
	while (tmp != NULL)
	{
		if (!(ps->tmp->next = (t_stack *)malloc(sizeof(t_stack))))
			ps_error(ps);
		ps->tmp->next->value = tmp->value;
		ps->tmp->next->position = tmp->position;
		ps->tmp->next->correct_position = tmp->correct_position;
		ps->tmp->next->next = NULL;
		ps->tmp = ps->tmp->next;
		tmp = tmp->next;
	}
	ps_sort_stack_k(ps);
}

void	ps_nonmechanical_sort(t_ps *ps)
{
	t_stack	*tmp;

	tmp = ps->a;
	if (!(ps->k = (t_stack *)malloc(sizeof(t_stack))))
		ps_error(ps);
	ps->k->value = tmp->value;
	ps->k->position = tmp->position;
	ps->k->correct_position = tmp->correct_position;
	ps->k->next = NULL;
	ps->tmp = ps->k;
	tmp = tmp->next;
	ps_continue_nonmechanical_sort(ps, tmp);
}
/*
 * Some tests:
 * ft_printf("\n%d in stack k is at pos. %d and cp. %d, iteration n. %d\n",
 * ps->tmp->value, ps->tmp->position, ps->tmp->correct_position, ps->i);
 */
