# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 18:18:19 by nkamolba          #+#    #+#              #
#    Updated: 2017/12/03 13:03:13 by terng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
LIBFT = libft/libft.a
FLAG = -Wall -Wextra -Werror
LIB = -Llibft -lft

UTILS_F = stack.c stack_utils.c ft_error.c operation.c read_input.c stack_operation.c
CHECKER_F = checker.c
PUSH_SWAP_F = push_swap.c

all : $(LIBFT) $(CHECKER) $(PUSH_SWAP)


$(LIBFT) :
	make -C libft

$(CHECKER) : | $(LIBFT)
	gcc $(FLAG) -o $(CHECKER) $(CHECKER_F) $(UTILS_F) $(LIB)

$(PUSH_SWAP) : | $(LIBFT)
	gcc $(FLAG) -o $(PUSH_SWAP) $(PUSH_SWAP_F) $(UTILS_F) $(LIB)
	
clean :
	make clean -C libft

fclean :
	make fclean -C libft
	rm -f $(CHECKER)
	rm -f $(PUSH_SWAP)

re : fclean all

.PHONY: all $(LIBFT) $(CHECKER) $(PUSH_SWAP) clean fclean re
