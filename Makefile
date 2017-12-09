# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 18:18:19 by nkamolba          #+#    #+#              #
#    Updated: 2017/12/09 20:04:21 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
LIBFT = libft/libft.a
FLAG = -Wall -Wextra -Werror
LIB = -Llibft -lft

UTILS_F		= 	stack.c stack_operation.c stack_utils.c \
				ft_error.c read_input.c operation.c
CHECKER_F	= 	checker.c
PUSH_SWAP_F	=	push_swap.c \
				op_t.c optimize_op.c stack_arrange.c\
				three_sort.c selection_sort.c short_sort.c 

UTILS_O = $(UTILS_F:%.c=%.o)
CHECKER_O = $(CHECKER_F:%.c=%.o)
PUSH_SWAP_O = $(PUSH_SWAP_F:%.c=%.o)

all : $(LIBFT) $(CHECKER) $(PUSH_SWAP)

$(LIBFT) :
	make -C libft

$(CHECKER) : $(CHECKER_O) $(UTILS_O)
	gcc $(FLAG) -o $(CHECKER) $(CHECKER_O) $(UTILS_O) $(LIB)

$(PUSH_SWAP) : $(PUSH_SWAP_O) $(UTILS_O)
	gcc $(FLAG) -o $(PUSH_SWAP) $(PUSH_SWAP_O) $(UTILS_O) $(LIB)
	
%.o: %.c
	gcc $(FLAG) -c $<

clean :
	make clean -C libft
	rm -f $(UTILS_O)
	rm -f $(CHECKER_O)
	rm -f $(PUSH_SWAP_O)

fclean : clean
	rm -f $(LIBFT)
	rm -f $(CHECKER)
	rm -f $(PUSH_SWAP)

re : fclean all

.PHONY: all $(LIBFT) $(CHECKER) $(PUSH_SWAP) clean fclean re
