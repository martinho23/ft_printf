/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:35:34 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/01 10:23:04 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t	getim(const char *format, t_fdata *data, va_list *ap)
{
	if (format[data->index] == 'D')
		return ((intmax_t)va_arg(*ap, long int));
	else if (data->len == 0)
		return ((intmax_t)va_arg(*ap, int));
	else if (data->len == 1)
		return ((intmax_t)va_arg(*ap, int));
	else if (data->len == 2)
		return ((intmax_t)va_arg(*ap, long int));
	else if (data->len == 3)
		return ((intmax_t)va_arg(*ap, long long int));
	else if (data->len == 4)
		return ((intmax_t)va_arg(*ap, intmax_t));
	else if (data->len == 5)
		return ((intmax_t)va_arg(*ap, size_t));
	else
		return ((intmax_t)va_arg(*ap, int));
}

static void		process(t_fdata *data, t_nbdata *nb, int *len)
{
	char	nba[nb->snb + 1];

	if (!data->flags[3] && !data->flags[0])
		pad(nb->spad, nb->pad);
	if (nb->nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb->nb = nb->nb * -1;
	}
	if (data->flags[0])
		pad(nb->spad, nb->pad);
	else if (data->flags[1] || data->flags[4])
		ft_putchar_fd(nb->poschar, 1);
	pad(nb->sprc, '0');
	ft_uimtoa_base((uintmax_t)nb->nb, nb->base, nba, BASE10);
	nba[nb->snb] = '\0';
	ft_putstr_fd(nba, 1);
	if (data->flags[3])
		pad(nb->spad, nb->pad);
	*len = nb->snb;
	*len += (nb->spad > 0) ? nb->spad : 0;
	*len += (nb->sprc > 0) ? nb->sprc : 0;
	*len += (nb->nb < 0 || data->flags[1] || data->flags[4]) ? 1 : 0;
}

int				int_handler(const char *format, t_fdata *data, va_list *ap)
{
	t_nbdata	nb;
	int			len;

	nb.nb = getim(format, data, ap);
	nb.base = 10;
	nb.snb = ft_imtoalen_base(nb.nb, nb.base);
	nb.spad = data->fwidth;
	nb.pad = ' ';
	nb.sprc = 0;
	nb.poschar = (data->flags[1]) ? '+' : ' ';
	data->index++;
	if (data->preci > -1)
	{
		nb.sprc = data->preci - nb.snb;
		nb.spad = nb.spad - nb.sprc;
	}
	else if (data->flags[0])
		nb.pad = '0';
	nb.spad = nb.spad - nb.snb;
	nb.spad -= (nb.nb < 0 || data->flags[1] || data->flags[4]) ? 1 : 0;
	process(data, &nb, &len);
	return (len);
 }
