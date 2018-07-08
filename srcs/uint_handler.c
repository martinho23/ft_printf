/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 05:17:51 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/08 18:37:29 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

static uintmax_t	getuim(const char *format, t_fdata *data, va_list *ap)
{
	if (format[data->index] == 'p')
		return ((uintmax_t)va_arg(*ap, void *));
	else if (data->len == 0)
		return ((short unsigned int)va_arg(*ap, unsigned int));
	else if (data->len == 1)
		return ((unsigned char)va_arg(*ap, unsigned int));
	else if (data->len == 2)
		return ((unsigned long int)va_arg(*ap, unsigned long int));
	else if (data->len == 3)
		return ((unsigned long long int)va_arg(*ap, unsigned long long int));
	else if (data->len == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (data->len == 5)
		return ((size_t)va_arg(*ap, size_t));
	else
		return ((unsigned int)va_arg(*ap, unsigned int));
}

static int			putconv(const char *format, t_fdata *data, t_nbdata *nb)
{
	if (nb->nb != 0)
	{
		if (format[data->index] == 'x' || format[data->index] == 'p')
			return (ft_putstr_fd("0x", 1));
		else if (format[data->index] == 'X')
			return (ft_putstr_fd("0X", 1));
		else if (format[data->index] == 'o' || format[data->index] == 'O')
			return (ft_putstr_fd("0", 1));
	}
	else
		if (format[data->index] == 'o' || format[data->index] == 'O')
			return (ft_putstr_fd("0", 1));
	return (0);
}

static int			process(const char *f, t_fdata *d, t_nbdata *nb)
{
	int		len;
	char	nba[1 + nb->snb];

	len = 0;
	if (!d->flags[3] && !d->flags[0])
		len += pad(nb->spad, nb->pad);
	if (d->flags[2])
		len += putconv(f, d, nb);
	if (!d->flags[3] && d->flags[0])
		len += pad(nb->spad, nb->pad);
	len += pad(nb->sprc, '0');
	if (f[d->index] == 'X')
	{
		ft_uimtoa_base(nb->nb, nb->base, nba, BASE16_C);
	}
	else
		ft_uimtoa_base(nb->nb, nb->base, nba, BASE16);
	if (d->preci != 0 || nb->nb != 0)
		len += ft_putnstr_fd(nba, nb->snb, 1);
	if (d->flags[3])
		len += pad(nb->spad, nb->pad);
	return (len);
}

static void			prep(const char *format, t_fdata *data, t_nbdata *nb)
{
	if (data->flags[2])
	{
		if (format[data->index] == 'o' || format[data->index] == 'O')
			nb->spad -= 1;
		else
			nb->spad -= (nb->nb != 0) ? 2 : 0;
	}
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

	nb.nb = getuim(format, d, ap);
	nb.spad = d->fwidth;
	prep(format, d, &nb);
	nb.snb = ft_uimtoalen_base(nb.nb, nb.base);
	nb.pad = ' ';
	nb.sprc = d->preci - nb.snb;
	if (nb.sprc > 0)
		nb.spad -= nb.sprc;
	else if (d->flags[0] && !d->flags[3])
		nb.pad = '0';
	if (d->preci != 0 || nb.nb != 0)
		nb.spad -= nb.snb;
	len = process(format, d, &nb);
	d->index++;
	return (len);
}
