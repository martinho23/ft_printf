/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 05:17:51 by jfarinha          #+#    #+#             */
/*   Updated: 2018/06/30 18:08:09 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

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

static void			putconv(const char *format, t_fdata *data)
{
	if (format[data->index] == 'x' || format[data->index] == 'p')
		ft_putstr_fd("0x", 1);
	else if (format[data->index] == 'X')
		ft_putstr_fd("0X", 1);
}

static void			process(const char *f, t_fdata *d, t_nbdata *nb, int *len)
{
	char	nba[nb->snb + 1];

	if (d->flags[2])
		putconv(f, d);
	pad(nb->sprc, '0');
	if (f[d->index] == 'X')
	{
		ft_uimtoa_base(nb->nb, nb->base, nba, BASE16_C);
	}
	else
		ft_uimtoa_base(nb->nb, nb->base, nba, BASE16);
	nba[nb->snb] = '\0';
	ft_putstr_fd(nba, 1);
	*len = nb->snb;
	*len += (nb->spad > 0) ? nb->spad : 0;
	*len += (nb->sprc > 0) ? nb->sprc : 0;
	*len += ft_strlen(nb->conv);
}

static void			prep(const char *format, t_fdata *data, t_nbdata *nb)
{
	if (format[data->index] == 'p')
	{
		data->flags[2] = 1;
		nb->base = 16;
	}
	else if (format[data->index] == 'x')
		nb->base = 16;
	else if (format[data->index] == 'X')
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

int					uint_handler(const char *format, t_fdata *data, va_list *ap)
{
	t_nbdata	nb;
	int			len;

	len = 0;
	prep(format, data, &nb);
	nb.nb = getuim(format, data, ap);
	nb.spad = data->fwidth;
	nb.snb = ft_uimtoalen_base(nb.nb, nb.base);
	nb.pad = ' ';
	nb.sprc = 0;
	if (data->preci > -1)
	{
		nb.sprc = data->preci - nb.snb;
		nb.spad = nb.spad - nb.sprc;
	}
	else if (data->flags[0])
		nb.pad = '0';
	nb.spad = nb.spad - nb.snb;
	(!data->flags[3]) ? pad(nb.spad, nb.pad) : process(format, data, &nb, &len);
	(data->flags[3]) ? pad(nb.spad, nb.pad) : process(format, data, &nb, &len);
	data->index++;
	return (len);
}
