/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 05:17:51 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/23 13:18:17 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void		prepconv(const char *format, t_fdata *data, t_nbdata *nb)
{
	if (data->flags[2] && (nb->unb || format[data->index] == 'p' || \
				format[data->index] == 'o' || format[data->index] == 'O'))
	{
		if ((format[data->index] == 'o' || format[data->index] == 'O') \
				&& (nb->unb || data->preci == 0))
		{
			nb->spad -= 1;
			nb->sprc -= 1;
		}
		else if (nb->unb || format[data->index] == 'p')
			nb->spad -= 2;
	}
}

static int			putconv(const char *format, t_fdata *data, t_nbdata *nb)
{
	if (nb->unb != 0)
	{
		if (format[data->index] == 'x' || format[data->index] == 'p')
			return (ft_putstr_fd("0x", 1));
		else if (format[data->index] == 'X')
			return (ft_putstr_fd("0X", 1));
		else if (format[data->index] == 'o' || format[data->index] == 'O')
			return (ft_putstr_fd("0", 1));
	}
	else
	{
		if (format[data->index] == 'p')
			return (ft_putstr_fd("0x", 1));
		else if ((format[data->index] == 'o' || format[data->index] == 'O') \
				&& data->preci == 0)
			return (ft_putstr_fd("0", 1));
	}
	return (0);
}

static int			process(const char *f, t_fdata *d, t_nbdata *nb)
{
	int		len;
	char	nba[1 + nb->snb];

	len = 0;
	if (!d->flags[3] && (!d->flags[0] || d->preci != -1))
		len += pad(d, nb->spad, nb->pad);
	if (d->flags[2])
		len += putconv(f, d, nb);
	if (!d->flags[3] && d->flags[0] && d->preci == -1)
		len += pad(d, nb->spad, nb->pad);
	len += pad(d, nb->sprc, '0');
	if (f[d->index] == 'X')
	{
		ft_uimtoa_base(nb->unb, nb->base, nba, BASE16_C);
	}
	else
		ft_uimtoa_base(nb->unb, nb->base, nba, BASE16);
	if (d->preci || nb->unb)
		len += ft_putnstr_fd(nba, nb->snb, d->fd);
	if (d->flags[3])
		len += pad(d, nb->spad, nb->pad);
	return (len);
}

static void			prep(const char *f, t_fdata *d, t_nbdata *nb)
{
	nb->base = 10;
	if (f[d->index] == 'p')
	{
		d->flags[2] = 1;
		nb->base = 16;
	}
	else if (f[d->index] == 'x' || f[d->index] == 'X')
		nb->base = 16;
	else if (f[d->index] == 'o' || f[d->index] == 'O')
		nb->base = 8;
	else if (f[d->index] == 'b')
		nb->base = 2;
	if (f[d->index] == 'O' || f[d->index] == 'U')
		d->len = 2;
}

int					uint_handler(const char *format, t_fdata *d, va_list *ap)
{
	t_nbdata	nb;
	int			len;

	nb.spad = d->fwidth;
	prep(format, d, &nb);
	nb.unb = getuim(format, d, ap);
	nb.snb = ft_uimtoalen_base(nb.unb, nb.base);
	nb.sprc = d->preci - nb.snb;
	nb.pad = ' ';
	prepconv(format, d, &nb);
	len = 0;
	if (nb.sprc > 0)
		nb.spad -= nb.sprc;
	else if (d->flags[0] && !d->flags[3] && d->preci == -1)
		nb.pad = '0';
	if (d->preci != 0 || nb.unb != 0 || format[d->index] == 'p')
		nb.spad -= nb.snb;
	len = process(format, d, &nb);
	d->index++;
	return (len);
}
