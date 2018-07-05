/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 05:17:51 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/05 06:04:06 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

static uintmax_t	getuim(const char *format, t_fdata *data, va_list *ap)
{
	if (format[data->index] == 'p')
		return ((uintmax_t)va_arg(*ap, void *));
	else if (data->len == 0)
		return ((uintmax_t)va_arg(*ap, unsigned int));
	else if (data->len == 1)
		return ((uintmax_t)va_arg(*ap, unsigned int));
	else if (data->len == 2)
		return ((uintmax_t)va_arg(*ap, unsigned long int));
	else if (data->len == 3)
		return ((uintmax_t)va_arg(*ap, unsigned long long int));
	else if (data->len == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (data->len == 5)
		return ((uintmax_t)va_arg(*ap, size_t));
	else
		return ((uintmax_t)va_arg(*ap, unsigned int));
}

static int			putconv(const char *format, t_fdata *data)
{
	if (format[data->index] == 'x' || format[data->index] == 'p')
		return (ft_putstr_fd("0x", 1));
	else if (format[data->index] == 'X')
		return (ft_putstr_fd("0X", 1));
	return (0);
}

static int			process(const char *f, t_fdata *d, t_nbdata *nb)
{
	int		len;
	char	nba[1 + nb->snb];

	len = (nb->sprc > 0) ? nb->sprc : 0;
	if (d->preci == 0 && nb->nb == 0)
		return (ft_putstr_fd("", 1));
	if (d->flags[2])
		len += putconv(f, d);
	pad(nb->sprc, '0');
	if (f[d->index] == 'X')
	{
		ft_uimtoa_base(nb->nb, nb->base, nba, BASE16_C);
	}
	else
		ft_uimtoa_base(nb->nb, nb->base, nba, BASE16);
	len += ft_putnstr_fd(nba, nb->snb, 1);
	return (len);
}

static void			prep(const char *format, t_fdata *data, t_nbdata *nb)
{
	if (format[data->index] == 'p')
	{
		data->flags[2] = 1;
		nb->base = 16;
	}
	else if (format[data->index] == 'x' ||format[data->index] == 'X')
		nb->base = 16;
	else if (format[data->index] == 'o')
		nb->base = 8;
	else if (format[data->index] == 'O')
		data->len = 2;
	else if (format[data->index] == 'U')
		data->len = 2;
	else
		nb->base = 10;
}

int					uint_handler(const char *format, t_fdata *d, va_list *ap)
{
	t_nbdata	nb;
	int			len;

	prep(format, d, &nb);
	nb.nb = getuim(format, d, ap);
	nb.spad = d->fwidth;
	nb.snb = ft_uimtoalen_base(nb.nb, nb.base);
	nb.pad = ' ';
	nb.sprc = 0;
	if (d->flags[2])
		nb.spad -= 2;
	if (d->preci > -1)
	{
		nb.sprc = d->preci - nb.snb;
		nb.spad = nb.spad - nb.sprc;
	}
	else if (d->flags[0])
		nb.pad = '0';
	nb.spad = nb.spad - nb.snb;
	len = (!d->flags[3]) ? pad(nb.spad, nb.pad) : process(format, d, &nb);
	len += (d->flags[3]) ? pad(nb.spad, nb.pad) : process(format, d, &nb);
	d->index++;
	return (len);
}
