/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:50:55 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 12:30:06 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	getflags(const char *format, t_fdata *data)
{
	int		flag_code;

	while (format[data->index] && (flag_code = \
			ft_getindice(FLAGS, format[data->index])) >= 0)
	{
		data->flags[flag_code] = 1;
		data->index++;
	}
}

static void	getprecison(const char *format, t_fdata *data, va_list *ap)
{
	if (format[data->index] == '.')
	{
		data->index++;
		if (format[data->index] == '*')
		{
			data->preci = (int)va_arg(*ap, int);
			data->index++;
		}
		else
		{
			data->preci = ft_atoi(&format[data->index]);
			while (ft_isdigit(format[data->index]))
				data->index++;
		}
	}
	else
		data->preci = -1;
}

static void	getwidth(const char *format, t_fdata *data, va_list *ap)
{
	data->fwidth = 0;
	while (ft_isdigit(format[data->index]) || format[data->index] == '*')
	{
		if (ft_isdigit(format[data->index]))
		{
			data->fwidth = ft_atoi(&format[data->index]);
			while (ft_isdigit(format[data->index]))
				data->index++;
		}
		if (format[data->index] == '*')
		{
			data->fwidth = (int)va_arg(*ap, int);
			data->index++;
		}
	}
	if (data->fwidth < 0)
	{
		data->fwidth *= -1;
		data->flags[3] = 1;
	}
}

static void	getlength(const char *format, t_fdata *data)
{
	data->len = ft_getindice(LENGTHS, format[data->index]);
	if (data->len >= 0)
	{
		data->index++;
		if ((format[data->index - 1] == 'l' && format[data->index] == 'l') ||\
			(format[data->index - 1] == 'h' && format[data->index] == 'h'))
		{
			data->len++;
			data->index++;
		}
	}
}

void		getdata(const char *format, t_fdata *data, va_list *ap)
{
	ft_bzero(&data->fwidth, sizeof(t_fdata) - (sizeof(data->index) + \
sizeof(data->counter) + sizeof(data->fd)));
	data->index++;
	getflags(format, data);
	getwidth(format, data, ap);
	getprecison(format, data, ap);
	getlength(format, data);
}
