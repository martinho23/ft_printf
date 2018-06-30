/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:17:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/06/29 17:07:46 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <../libft/libft.h>
#include "../includes/ft_printf.h"

static int		printraw(const char *format, t_fdata *data)
{
	int		i;

	i = 0;
	while (format[data->index + i] && format[data->index + i] != '%')
		i++;
	write(1, &format[data->index], (t_size)i);
	data->index += i;
	return (i);
}

static void		funcinit(int (*func[14])(const char *, t_fdata *, va_list *))
{
	func[0] = string_handler;
	func[1] = string_handler;
	func[2] = int_handler;
	func[3] = int_handler;
	func[4] = int_handler;
	func[5] = uint_handler;
	func[6] = uint_handler;
	func[7] = uint_handler;
	func[8] = uint_handler;
	func[9] = uint_handler;
	func[10] = uint_handler;
	func[11] = uint_handler;
	func[12] = char_handler;
	func[13] = char_handler;
}

static int		printformat(const char *format, t_fdata *data, va_list *ap)
{
	int		op;
	int		(*func[14])(const char *, t_fdata *, va_list *);

	funcinit(func);
	getdata(format, data);
	op = ft_getindice(CONVERTIONS, format[data->index]);
	return ((op < 14 && op >= 0) ? func[op](format, data, ap) : (-1));
}

int				ft_printf(const char *format, ...)
{
	t_fdata	data;
	int				rval;
	int				tmp;
	va_list			ap;


	data.index = 0;
	rval = 0;
	va_start(ap, format);
	while (format[data.index] && rval != (-1))
	{
		if (format[data.index] == '%' && format[data.index + 1] != '%')
			rval = ((tmp = printformat(format, &data, &ap)) == -1) ? \
			(-1) : tmp + rval;
		else
			rval += printraw(format, &data);
	}
	va_end(ap);
	return (rval);
}
