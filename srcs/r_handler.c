/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:58:30 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/01 13:04:41 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	init_r_handler(t_fdata *data, int len, int *pad)
{
	*pad = data->fwidth;
	len = (data->preci >= 0 && data->preci < len) ? data->preci : len;
	*pad = *pad - len;
	return (len);
}

static int	process(const char *format, t_fdata *d, void *str)
{
	int		l;
	int		padding;
	char	padc;

	(void)format;
	padc = (d->flags[0]) ? '0' : ' ';
	str = (char *)str;
	l = ft_uprintlen(str);
	l = init_r_handler(d, l, &padding);
	(!d->flags[3]) ? pad(d, padding, padc) : ft_putnuprint_fd(str, d->fd, l);
	(d->flags[3]) ? pad(d, padding, padc) : ft_putnuprint_fd(str, d->fd, l);
	if (padding > 0)
		return (l + padding);
	return (l);
}

int			r_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	char	*str;

	str = (char *)va_arg(*ap, char *);
	len = process(format, data, str);
	data->index++;
	return (len);
}
