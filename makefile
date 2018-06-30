# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 14:55:06 by jfarinha          #+#    #+#              #
#    Updated: 2018/06/29 17:03:34 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=libftprintf.a
LIB :=libft/libft.a
FILES :=ft_printf	getdata	printf_utils	chars_handler	string_handler\
		int_handler	uint_handler
BINS :=$(FILES:=.o)
BINS :=$(addprefix srcs/, $(BINS))
INC :=includes
FLAGS :=-Wall -Werror -Wextra



.PHONY: all clean fclean re output
all:$(NAME) $(LIB)

$(LIB):
	make -C libft

%.o:%.c
	gcc $(FLAGS) -o $@ -I $(INC) -c $<

$(NAME):$(BINS)
	ar -rc $@ $^
	ranlib $@

clean:
	rm -rf $(BINS)

fclean:clean
	rm -f $(NAME)

re:fclean all
