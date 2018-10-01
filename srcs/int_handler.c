/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:35:34 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/01 15:28:32 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t	getim(const char *format, t_fdata *data, va_list *ap)
{
	if (format[data->index] == 'D')
		return ((long int)va_arg(*ap, intmax_t));
	else if (data->len == 0)
		return ((short int)va_arg(*ap, intmax_t));
	else if (data->len == 1)
		return ((char)va_arg(*ap, intmax_t));
	else if (data->len == 2)
		return ((long int)va_arg(*ap, intmax_t));
	else if (data->len == 3)
		return ((long long int)va_arg(*ap, intmax_t));
	else if (data->len == 4)
		return ((intmax_t)va_arg(*ap, intmax_t));
	else if (data->len == 5)
		return ((size_t)va_arg(*ap, intmax_t));
	else
		return ((int)va_arg(*ap, intmax_t));
}

static void		process(t_fdata *data, t_nbdata *nb, int *len)
{
	char	nba[nb->snb + 1];

	*len = 0;
	if ((!data->flags[3] && !data->flags[0]) || data->preci != -1)
		*len = pad(data, nb->spad, nb->pad);
	*len += ft_putnstr_fd(&nb->poschar, 1, data->fd);
	if (data->flags[0] && !data->flags[3] && data->preci == -1)
		*len += pad(data, nb->spad, nb->pad);
	if (nb->nb < 0)
		nb->unb = nb->nb * -1;
	else
		nb->unb = (uintmax_t)nb->nb;
	*len += pad(data, nb->sprc, '0');
	ft_uimtoa_base(nb->unb, nb->base, nba, BASE10);
	nba[nb->snb] = '\0';
	if (data->preci != 0 || nb->nb != 0)
		*len += ft_putstr_fd(nba, data->fd);
	if (data->flags[3])
		*len += pad(data, nb->spad, nb->pad);
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
	nb.poschar = (data->flags[4]) ? ' ' : '\0';
	nb.poschar = (data->flags[1]) ? '+' : nb.poschar;
	nb.poschar = (nb.nb < 0) ? '-' : nb.poschar;
	data->index++;
	if (data->preci > -1)
	{
		nb.sprc = data->preci - nb.snb;
		nb.spad = (nb.sprc > 0) ? nb.spad - nb.sprc : nb.spad;
	}
	else if (data->flags[0] && !data->flags[3])
		nb.pad = '0';
	nb.spad = (data->preci == 0 && nb.nb == 0) ? nb.spad : nb.spad - nb.snb;
	nb.spad -= (nb.nb < 0 || data->flags[1] || data->flags[4]) ? 1 : 0;
	process(data, &nb, &len);
	return (len);
}
