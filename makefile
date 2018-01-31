# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 14:55:06 by jfarinha          #+#    #+#              #
#    Updated: 2018/01/26 22:37:30 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
BINS=$(patsubst %, bins/%.o, $(FILES))
SRCS=$(patsubst %, srcs/%.c, $(FILES))
INC=includes	libft
LIBDIR=libft
LIB=ft
FLAGS=-Wall -Werror -Wextra
FILES=is_left_adjusted	process_precision	process_fwidth

all:bins $(NAME)

bins:
	-mkdir bins

$(LIB):
	make -C libft

bins/%.o:srcs/%.c $(LIB)
	gcc $(FLAGS) -L$(LIBDIR) -l$(LIB) -o$@ -c -I$(INC) $<

$(NAME):$(BINS)
	ar -rc $(NAME) $(BINS)
	ranlib $(NAME)

.PHONY: all clean fclean re

clean:
	rm -f $(BINS)

fclean:clean
	rm -f $(NAME)

re:fclean all
