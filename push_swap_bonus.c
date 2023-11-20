/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:46:22 by fporciel          #+#    #+#             */
/*   Updated: 2023/11/20 13:26:50 by fporciel         ###   ########.fr       */
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

static int	psc_issorted(t_stack *head)
{
	while (head)
	{
		if (head->next && (head->value > head->next->value))
			return (0);
		head = head->next;
	}
	return (1);
}

static void	psc_check_order(t_ps *ps, int argc)
{
	if ((ps->a == NULL) || (ps->b != NULL) || (ps_stacksize(ps->a) != argc))
	{
		if ((int)write(1, "KO\n", 3) < 0)
			ps_error(ps);
		return ;
	}
	if (!psc_issorted(ps->a))
	{
		if ((int)write(1, "KO\n", 3) < 0)
			ps_error(ps);
		return ;
	}
	if ((int)write(1, "OK\n", 3) < 0)
		ps_error(ps);
}

static void	psc_execute(t_ps *ps, char *move)
{
	if ((move[0] == 112) && (move[1] == 97))
		ps_push_in_a(ps);
	else if ((move[0] == 112) && (move[1] == 98) && (move[2] == 10))
		ps_push_in_b(ps);
	else if ((move[0] == 115) && (move[1] == 97) && (move[2] == 10))
		ps_swap_a(ps);
	else if ((move[0] == 115) && (move[1] == 98) && (move[2] == 10))
		ps_swap_b(ps);
	else if ((move[0] == 115) && (move[1] == 115) && (move[2] == 10))
		ps_swap_s(ps);
	else if ((move[0] == 114) && (move[1] == 97) && (move[2] == 10))
		ps_rotate_a(ps);
	else if ((move[0] == 114) && (move[1] == 98) && (move[2] == 10))
		ps_rotate_b(ps);
	else if ((move[0] == 114) && (move[1] == 114) && (move[2] == 10))
		ps_rotate_r(ps);
	else if ((move[0] == 114) && (move[1] == 114) && (move[2] == 97))
		ps_revrotate_a(ps);
	else if ((move[0] == 114) && (move[1] == 114) && (move[2] == 98))
		ps_revrotate_b(ps);
	else if ((move[0] == 114) && (move[1] == 114) && (move[2] == 114))
		ps_revrotate_r(ps);
	else
		ps_error(ps);
}

static void	psc_continue_checker(t_ps *ps)
{
	char	*move;
	size_t	mlen;

	move = ft_strdup("");
	if (move == NULL)
		ps_error(ps);
	while (move != NULL)
	{
		free(move);
		errno = 0;
		move = get_next_line(0);
		if ((move == NULL) && ((errno == ENOMEM)
				|| (errno == EAGAIN) || (errno == EWOULDBLOCK)
				|| (errno == EBADF) || (errno == EFAULT) || (errno == EINTR)
				|| (errno == EINVAL) || (errno == EIO)))
			ps_error(ps);
		if (move == NULL)
			break ;
		mlen = ft_strlen(move);
		if ((mlen > 4) || (mlen < 3) || (move[mlen - 1] != 10))
			ps_error(ps);
		psc_execute(ps, move);
	}
}

int	main(int argc, char **argv)
{
	static t_ps	ps;

	if (argc == 1)
		ps_error(&ps);
	argv++;
	argc--;
	ps_stack_generator(argv, &ps);
	ps_check_correct_position(&ps);
	psc_continue_checker(&ps);
	psc_check_order(&ps, argc);
	ps_success(&ps);
	return (1);
}
