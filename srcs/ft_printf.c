/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:17:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 15:08:04 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"

static int		printraw(const char *f, t_fdata *d)
{
	int		i;

	i = 0;
	while (f[d->index + i] && f[d->index + i] != '%' && f[d->index + i] != '{')
		i++;
	write(d->fd, &f[d->index], (t_size)i);
	d->index += i;
	return (i);
}

static void		funcinit(int (*func[CNVN])(const char *, t_fdata *, va_list *))
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
	func[14] = percent_handler;
	func[15] = uint_handler;
	func[16] = n_handler;
	func[17] = r_handler;
}

static int		printformat(const char *format, t_fdata *data, va_list *ap)
{
	int		op;
	int		(*func[CNVN])(const char *, t_fdata *, va_list *);

	funcinit(func);
	getdata(format, data, ap);
	op = ft_getindice(CONVERTIONS, format[data->index]);
	return ((op < CNVN && op >= 0) ? func[op](format, data, ap) : 0);
}

static int		management(const char *format, t_fdata *data, va_list *ap)
{
	if (ft_strstr(&format[data->index], "{fd}"))
	{
		data->fd = va_arg(*ap, int);
		data->index += 4;
	}
	else
	{
		data->index += 1;
		return (ft_putchar_fd('{', data->fd));
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	t_fdata			data;
	int				tmp;
	va_list			ap;

	data.index = 0;
	data.counter = 0;
	data.fd = 1;
	va_start(ap, format);
	while (format[data.index] && data.counter != (-1))
	{
		if (format[data.index] == '%')
		{
			tmp = printformat(format, &data, &ap);
			data.counter = (tmp != -1) ? tmp + data.counter : -1;
		}
		else if (format[data.index] == '{')
			data.counter += management(format, &data, &ap);
		else
			data.counter += printraw(format, &data);
	}
	va_end(ap);
	return (data.counter);
}
