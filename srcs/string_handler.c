/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:58:30 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/23 17:18:15 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

static int	init_string_handler(t_fdata *data, int len, int *pad)
{
	int		rlen;

	rlen = (data->fwidth > len) ? data->fwidth : len;
	rlen = (data->preci >= 0 && data->preci < rlen) ? data->preci : rlen;
	*pad = (rlen > len) ? rlen - len : 0;

	if (data->flags[0])
		return (-1);
	if (data->flags[1])
		return (-1);
	if (data->flags[2])
		return (-1);
	if (data->flags[4])
		return (-1);
	if (data->len != 2 && data->len != (-1))
		return (-1);
	return (rlen);
}

int			string_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	int		padding;
	void	*str;

	if (data->len == 2 || format[data->index] == 'S')
	{
		str = (wchar_t *)va_arg(*ap, wchar_t *);
		len = ft_wstrlen(str);
		len = init_string_handler(data, len, &padding);
		(!data->flags[3]) ? pad(padding, ' ') : ft_putnwstr_fd(str, len, 1);
		(data->flags[3]) ? pad(padding, ' ') : ft_putnwstr_fd(str, len, 1);
	}
	else
	{
		str = (char *)va_arg(*ap, char *);
		len = ft_strlen(str);
		len = init_string_handler(data, len, &padding);
		(!data->flags[3]) ? pad(padding, ' ') : ft_putnstr_fd(str, len, 1);
		(data->flags[3]) ? pad(padding, ' ') : ft_putnstr_fd(str, len, 1);
	}
	data->index++;
	return (len);
}
