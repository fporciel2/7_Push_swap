# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:26:54 by fporciel          #+#    #+#              #
#    Updated: 2023/12/07 10:27:08 by fporciel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# 
# Push_swap is a versatile sorting algorithm visualization tool. Designed as
# a part of a programming challenge, they demonstrate the efficiency of
# different sorting algorithms by visually displaying their operations.
# The Push_swap and Checker programs are designed to work together for
# sorting integers using a set of specific instructions while visualizing the
# sorting process. Push_swap generates a sequence of instructions to sort a
# list of numbers, and Checker verifies whether these instructions are valid
# and successfully sort the list.
# 
# Copyright (C) 2023  Federico Porciello
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

.PHONY: all bonus clean fclean re rebonus norm dft ft dprintf printf \
	autogit memcheck dfclean both
.DEFAULT_GOAL: all
DIR := $(shell pwd)
FTDIR := $(DIR)/1_libft
PRINTFDIR := $(DIR)/2_ft_printf
FT := $(FTDIR)/libft.a
PRINTF := $(PRINTFDIR)/libftprintf.a
NAME := $(DIR)/push_swap
BNAME := $(DIR)/checker
SRCS := $(filter-out %bonus.c, $(wildcard push_swap*.c))
BSRCS := $(filter-out push_swap.c, $(wildcard push_swap*.c))
OBJS := $(patsubst %.c, %.o, $(SRCS))
BOBJS := $(patsubst %.c, %.o, $(BSRCS))
PSH := $(DIR)/push_swap.h
BPSH := $(DIR)/checker.h
FTH := $(FTDIR)/libft.h
PRINTFH := $(PRINTFDIR)/ft_printf.h
CC := gcc
CFLAGS := -std=c17 -pedantic -Wall -Wextra -Werror -O3 -march=native -g
INCLUDE := $(addprefix -I, $(DIR) $(FTDIR) $(PRINTFDIR))
LIBS := $(addprefix -L, $(FTDIR) $(PRINTFDIR))
LFLAGS := -lc -lft -lftprintf

all: $(FT) $(PRINTF) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBS) $(LFLAGS) -o $(NAME)

bonus: $(FT) $(PRINTF) $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(BOBJS) $(LIBS) $(LFLAGS) -o $(BNAME)

ft: $(FT)

$(FT): dft
	@if [ ! -e $(FT) ]; \
		then cd $(FTDIR) && make bonus && cd ..; fi

dft:
	@if [ ! -e $(FTDIR) ]; \
		then git clone https://github.com/fporciel2/1_libft.git; fi

printf: $(PRINTF)

$(PRINTF): dprintf
	@if [ ! -e $(PRINTF) ]; \
		then cd $(PRINTFDIR) && make && cd ..; fi

dprintf:
	@if [ ! -e $(PRINTFDIR) ]; \
		then git clone https://github.com/fporciel2/2_ft_printf.git; fi

$(OBJS): $(FT) $(PRINTF) $(SRCS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCS)

$(BOBJS): $(FT) $(PRINTF) $(BSRCS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $(BSRCS)

norm:
	@norminette $(SRCS) $(BSRCS) $(PSH) $(BPSH) $(FTH) $(PRINTFH) \
		$(FTDIR)/*.c $(PRINTFDIR)/*.c

both:
	@make dfclean
	@make
	@make clean
	@rm -f $(FT) $(PRINTF)
	@make bonus

clean:
	@rm -f $(OBJS)
	@rm -f $(BOBJS)
	@if [ -e $(FTDIR) ]; \
		then cd $(FTDIR) && make clean && cd ..; fi
	@if [ -e $(PRINTFDIR) ]; \
		then cd $(PRINTFDIR) && make clean && cd ..; fi

fclean: clean
	@rm -f $(NAME) $(BNAME) $(FT) $(PRINTF)

re: clean fclean all

rebonus: clean fclean bonus

dfclean: clean fclean
	@rm -rfd 1_libft
	@rm -rfd 2_ft_printf

autogit: dfclean
	@git status
	@git add *
	@git status
	@echo "\nPlease, enter your commit message:"
	@read commit_message; git commit -m "$$commit_message"
	@git status
	@git push

memcheck:
	@echo "\nPlease, enter your input to test:"
	@read input_list; \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --show-error-list=yes -s -v ./push_swap $$input_list

