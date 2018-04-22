# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 14:55:06 by jfarinha          #+#    #+#              #
#    Updated: 2018/04/22 23:20:46 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
BINS=$(patsubst %, srcs/%.o, $(FILES))
SRCS=$(patsubst %, srcs/%.c, $(FILES))
INC=includes
FLAGS=-Wall -Werror -Wextra
FILES=	ft_printf	getdata	printf_utils	chars_handler\
		ft_isdigit	ft_getindice	ft_atoi	ft_bzero	ft_isspace	ft_memset\
		ft_putchar	ft_putchar_fd

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
