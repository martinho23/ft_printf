# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 14:55:06 by jfarinha          #+#    #+#              #
#    Updated: 2018/07/04 07:34:28 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=libftprintf.a
FILES :=ft_printf	getdata	printf_utils	chars_handler	string_handler\
		int_handler	uint_handler	percent_handler\
		ft_atoi	ft_isdigit	ft_getindice	ft_bzero	ft_putchar_fd	\
		ft_wstrlen	ft_putnwstr_fd	ft_strlen	ft_putnstr_fd	ft_uimtoa_base\
		ft_imtoalen_base	ft_uimtoalen_base	ft_isspace	ft_wcharlen\
		ft_memset	ft_putstr_fd
BINS :=$(FILES:=.o)
BINS :=$(addprefix srcs/, $(BINS))
INC :=includes
FLAGS :=-Wall -Werror -Wextra



.PHONY: all clean fclean re output
all:$(NAME)

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
