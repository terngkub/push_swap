# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 18:18:19 by nkamolba          #+#    #+#              #
#    Updated: 2017/12/02 18:36:05 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
FLAG = -Wall -Wextra -Werror

CHECKER_F = checker.c stack.c ft_error.c operation.c read_input.c stack_operation.c

all : $(CHECKER)

$(CHECKER) :
	make -C libft
	gcc $(FLAG) -o $(CHECKER) $(CHECKER_F) -Llibft -lft
	
clean :
	make clean -C libft

fclean : clean
	make fclean -C libft
	rm -f $(CHECKER)

re : fclean all

.PHONY: all $(NAME) clean fclean re
