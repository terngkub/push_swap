# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 18:18:19 by nkamolba          #+#    #+#              #
#    Updated: 2017/12/13 16:15:04 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
CHECKER = checker
PUSH_SWAP = push_swap

CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Llibft -lft

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
	@make -C libft

$(CHECKER) : $(CHECKER_O) $(UTILS_O) | $(LIBFT)
	@gcc $(CFLAGS) -o $(CHECKER) $(CHECKER_O) $(UTILS_O) $(INCLUDE)
	@echo "checker created"

$(PUSH_SWAP) : $(PUSH_SWAP_O) $(UTILS_O) | $(LIBFT)
	@gcc $(CFLAGS) -o $(PUSH_SWAP) $(PUSH_SWAP_O) $(UTILS_O) $(INCLUDE)
	@echo "push_swap created"
	
%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean :
	@make clean -C libft
	@rm -f $(UTILS_O)
	@rm -f $(CHECKER_O)
	@echo "$(CHECKER) clean done"
	@rm -f $(PUSH_SWAP_O)
	@echo "$(PUSH_SWAP) clean done"
	@echo "_____________________"

fclean : clean
	@rm -f $(LIBFT)
	@echo "libft.a fclean done"
	@rm -f $(CHECKER)
	@echo "$(CHECKER) fclean done"
	@rm -f $(PUSH_SWAP)
	@echo "$(PUSH_SWAP) fclean done"
	@echo "_____________________"

re : fclean all

.PHONY: all clean fclean re
