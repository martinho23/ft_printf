/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:22:41 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/07 16:28:49 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	init_char_handler(t_fdata *data, int *padding, int c)
{
	int		cnbr;

	cnbr = (data->fwidth > 1) ? data->fwidth : 1;
	*padding = data->fwidth;
	*padding -= (c == 0) ? 2 : 1;
	return (cnbr);
}

int			process(int c, int fd)
{
	if (c == 0)
		return (ft_putstr_fd("^@", fd));
	else
		return (ft_putchar_fd(c, fd));
}

int			char_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	int		padding;
	int		c;

	if (data->len == 2 || format[data->index] == 'C')
		c = va_arg(*ap, wchar_t);
	else
		c = va_arg(*ap, int);
	data->index++;
	len = init_char_handler(data, &padding, c);
	if (len == (-1))
		return (-1);
	(!data->flags[3]) ? pad(padding, ' ') : process(c, 1);
	(data->flags[3]) ? pad(padding, ' ') : process(c, 1);
	return (len);
}
