/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:58:30 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/23 12:56:48 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	init_string_handler(t_fdata *data, int len, int *pad)
{
	*pad = data->fwidth;
	len = (data->preci >= 0 && data->preci < len) ? data->preci : len;
	*pad = *pad - len;
	return (len);
}

static int	wprocess(t_fdata *d, wchar_t *str, int padc)
{
	int		l;
	int		r;
	int		padg;
	char	put[ft_wstrlen(str)];

	l = 0;
	r = 0;
	while (*str)
	{
		r = ft_wctoa((unsigned char *)&put[l], *str++);
		if (!r)
			return (-1);
		if (d->preci > -1 && r + l > d->preci)
			break ;
		l += r;
	}
	l = init_string_handler(d, l, &padg);
	r = (!d->flags[3]) ? pad(d, padg, padc) : ft_putnstr_fd(put, l, d->fd);
	r += (d->flags[3]) ? pad(d, padg, padc) : ft_putnstr_fd(put, l, d->fd);
	return (r);
}

static int	process(const char *format, t_fdata *d, void *str)
{
	int		l;
	int		r;
	int		padg;
	char	padc;

	padc = (d->flags[0]) ? '0' : ' ';
	r = 0;
	if (d->len == 2 || format[d->index] == 'S')
		return (wprocess(d, (wchar_t *)str, padc));
	else
	{
		str = (char *)str;
		l = ft_strlen(str);
		l = init_string_handler(d, l, &padg);
		r = (!d->flags[3]) ? pad(d, padg, padc) : ft_putnstr_fd(str, l, d->fd);
		r += (d->flags[3]) ? pad(d, padg, padc) : ft_putnstr_fd(str, l, d->fd);
	}
	return (r);
}

int			string_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	void	*str;

	if (data->len == 2 || format[data->index] == 'S')
	{
		if ((str = (wchar_t *)va_arg(*ap, wchar_t *)) == NULL)
			str = L"(null)";
	}
	else
	{
		if ((str = (char *)va_arg(*ap, char *)) == NULL)
			str = "(null)";
	}
	len = process(format, data, str);
	data->index++;
	return (len);
}
