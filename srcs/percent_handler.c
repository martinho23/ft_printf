/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:21:05 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/25 11:17:39 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		percent_handler(const char *format, t_fdata *d, va_list *ap)
{
	int		len;
	char	wc;

	(void)format;
	(void)ap;
	if (format[d->index] == '%')
	{
		if (d->flags[0])
			wc = '0';
		else
			wc = ' ';
		len = (!d->flags[3]) ? pad(d->fwidth - 1, wc) : ft_putstr_fd("%", 1);
		len += (d->flags[3]) ? pad(d->fwidth - 1, wc) : ft_putstr_fd("%", 1);
		d->index++;
	}
	else
		len = ft_putchar_fd('%', 1);
	return (len);
}
