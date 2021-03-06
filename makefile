# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 14:55:06 by jfarinha          #+#    #+#              #
#    Updated: 2018/10/11 12:33:20 by jfarinha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a
FILES :=ft_printf	getdata	printf_utils	chars_handler	string_handler\
		int_handler	uint_handler	percent_handler	n_handler	r_handler\
		ft_atoi	ft_isdigit	ft_getindice	ft_bzero	ft_putchar_fd	\
		ft_wstrlen	ft_putnwstr_fd	ft_strlen	ft_putnstr_fd	ft_uimtoa_base\
		ft_imtoalen_base	ft_uimtoalen_base	ft_isspace	ft_wcharlen\
		ft_memset	ft_putstr_fd	ft_strstr	ft_isprint	ft_strncpy\
		ft_putnuprint_fd	ft_uprintlen	ft_wctoa	ft_validutf8\
		ft_putwchar_fd
BINS :=$(FILES:=.o)
BINS :=$(addprefix srcs/, $(BINS))
INC :=includes
FLAGS :=-Wall -Werror -Wextra



.PHONY: all clean fclean re output
all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -I $(INC) -c $<

$(NAME): $(BINS)
	ar -rc $@ $^
	ranlib $@

clean:
	rm -f $(BINS)

fclean: clean
	rm -f $(NAME)

re:fclean all
