/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:22:41 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 14:36:46 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	init_char_handler(t_fdata *data, int *padding)
{
	int		cnbr;

	cnbr = (data->fwidth > 1) ? data->fwidth : 1;
	*padding = data->fwidth - 1;
	return (cnbr);
}

int			char_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	int		padding;
	int		c;
	int		(*putchar)(int, int);
	char	padc;

	len = 0;
	padc = (data->flags[0]) ? '0' : ' ';
	if (data->len == 2 || format[data->index] == 'C')
	{
		c = va_arg(*ap, wchar_t);
		putchar = &ft_putwchar_fd;
	}
	else
	{
		c = (char)va_arg(*ap, int);
		putchar = &ft_putchar_fd;
	}
	data->index++;
	init_char_handler(data, &padding);
	len += (!data->flags[3]) ? pad(data, padding, padc) : putchar(c, data->fd);
	len += (data->flags[3]) ? pad(data, padding, padc) : putchar(c, data->fd);
	return (len);
}
