/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:22:41 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/22 21:52:24 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static int	init_char_handler(t_fdata *data, int *padding)
{
	int		cnbr;

	cnbr = (data->fwidth > 1) ? data->fwidth : 1;
	*padding = data->fwidth - 1;
	if (data->precision != (-1))
		return (-1);
	if (data->flags[0])
		return (-1);
	if (data->flags[1])
		return (-1);
	if (data->flags[2])
		return (-1);
	if (data->flags[4])
		return (-1);
	if (data->len != 2 && data->len != (-1))
		return (-1);
	return (cnbr);
}

int			char_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	int		padding;
	int		c;

	len = init_char_handler(data, &padding);
	if (data->len == 2 || format[data->index] == 'C')
		c = va_arg(*ap, wchar_t);
	else
		c = va_arg(*ap, int);
	data->index++;
	if (len == (-1))
		return (-1);
	(data->flags[3]) ? pad(padding, ' ') : ft_putchar(c);
	(!data->flags[3]) ? pad(padding, ' ') : ft_putchar(c);
	return (len);
}
