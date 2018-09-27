/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:21:05 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 13:27:42 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		percent_handler(const char *format, t_fdata *d, va_list *ap)
{
	int		len;
	char	w;

	(void)format;
	(void)ap;
	if (format[d->index] == '%')
	{
		if (d->flags[0])
			w = '0';
		else
			w = ' ';
		len = (!d->flags[3]) ? pad(d, d->fwidth - 1, w) : ft_putstr_fd("%",\
d->fd);
		len += (d->flags[3]) ? pad(d, d->fwidth - 1, w) : ft_putstr_fd("%",\
d->fd);
		d->index++;
	}
	else
		len = ft_putchar_fd('%', d->fd);
	return (len);
}
