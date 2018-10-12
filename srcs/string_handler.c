/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:58:30 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 13:31:52 by jfarinha         ###   ########.fr       */
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

static int	process(const char *format, t_fdata *d, void *str)
{
	int		l;
	int		padding;
	char	padc;

	padc = (d->flags[0]) ? '0' : ' ';
	if (d->len == 2 || format[d->index] == 'S')
	{
		str = (wchar_t *)str;
		l = ft_wstrlen(str);
		l = init_string_handler(d, l, &padding);
		(!d->flags[3]) ? pad(d, padding, padc) : ft_putnwstr_fd(str, l, d->fd);
		(d->flags[3]) ? pad(d, padding, padc) : ft_putnwstr_fd(str, l, d->fd);
	}
	else
	{
		str = (char *)str;
		l = ft_strlen(str);
		l = init_string_handler(d, l, &padding);
		(!d->flags[3]) ? pad(d, padding, padc) : ft_putnstr_fd(str, l, d->fd);
		(d->flags[3]) ? pad(d, padding, padc) : ft_putnstr_fd(str, l, d->fd);
	}
	if (padding > 0)
		return (l + padding);
	return (l);
}

int			string_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	void	*str;

	if (data->len == 2 || format[data->index] == 'S')
		str = (wchar_t *)va_arg(*ap, wchar_t *);
	else
		str = (char *)va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	len = process(format, data, str);
	data->index++;
	return (len);
}
