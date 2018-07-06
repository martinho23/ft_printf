/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:35:34 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/06 05:44:25 by jfarinha         ###   ########.fr       */
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

	*len = 0;
	if (!data->flags[3] && !data->flags[0])
		*len = pad(nb->spad, nb->pad);
	*len += ft_putnstr_fd(&nb->poschar, 1, 1);
	if (data->flags[0])
		*len += pad(nb->spad, nb->pad);
	if (nb->nb < 0)
		nb->nb = nb->nb * -1;
	*len += pad(nb->sprc, '0');
	ft_uimtoa_base((uintmax_t)nb->nb, nb->base, nba, BASE10);
	nba[nb->snb] = '\0';
	if (data->preci != 0 || nb->nb != 0)
		*len += ft_putstr_fd(nba, 1);
	if (data->flags[3])
		*len += pad(nb->spad, nb->pad);
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
	nb.poschar = (nb.nb < 0)? '-' : nb.poschar;
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
