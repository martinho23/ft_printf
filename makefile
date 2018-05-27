# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 14:55:06 by jfarinha          #+#    #+#              #
#    Updated: 2018/04/23 15:13:55 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
BINS=$(patsubst %, srcs/%.o, $(FILES))
SRCS=$(patsubst %, srcs/%.c, $(FILES))
INC=includes
FLAGS=-Wall -Werror -Wextra
FILES=	ft_printf	getdata	printf_utils	chars_handler	string_handler\
		ft_isdigit	ft_getindice	ft_atoi	ft_bzero	ft_isspace	ft_memset\
		ft_putchar_fd	ft_atoi	ft_putnstr_fd	ft_putnwstr_fd	ft_wcharlen\
		ft_wstrlen	ft_strlen

all:$(NAME)

%.o:%.c $(LIB)
	gcc $(FLAGS) -o$@ -c -I$(INC) $<

$(NAME):$(BINS)
	ar -rc $(NAME) $(BINS)
	ranlib $(NAME)

clean:
	rm -f $(BINS)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
