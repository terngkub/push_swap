# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 09:11:21 by nkamolba          #+#    #+#              #
#    Updated: 2017/12/10 11:57:06 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE =	ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp\
		ft_strlen ft_strdup ft_strcpy ft_strncpy\
		ft_strcat ft_strncat ft_strlcat\
		ft_strchr ft_strrchr ft_strstr ft_strnstr\
		ft_strcmp ft_strncmp ft_atoi\
		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
		ft_toupper ft_tolower\
		ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr\
		ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ\
		ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_itoa\
		ft_putchar ft_putstr ft_putendl ft_putnbr\
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
		ft_countword ft_wordlen ft_getword ft_skipc ft_skiptoc\
		ft_numlen ft_power ft_itoa_base ft_strfreecat_back ft_strfreecat_front\
		ft_putstr_len ft_strfncat_back ft_strfncat_front\
		ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap\
		ft_lstpushback ft_lstprint ft_lstsearch ft_lstrev\
		get_next_line
		
FILE_O = $(addsuffix .o, $(FILE))

PNTF =	ft_printf read_input get_conv get_data\
		get_num get_str get_wchar get_ptr\
		handle_flag handle_wp

PNTF_O = $(addprefix ft_printf/, $(addsuffix .o, $(PNTF)))

all: $(NAME)

$(NAME): $(FILE_O) $(PNTF_O)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo "$(NAME) created"

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(FILE_O) $(PNTF_O)
	@echo "$(NAME) clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) fclean done"

re: fclean all

.PHONY: all clean fclean re
