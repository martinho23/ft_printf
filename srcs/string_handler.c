/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:58:30 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/25 14:50:26 by jfarinha         ###   ########.fr       */
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

static int	process(const char *format, t_fdata *data, void *str)
{
	int		len;
	int		padding;
	char	padc;

	padc = (data->flags[0]) ? '0' : ' ';
	if (data->len == 2 || format[data->index] == 'S')
	{
		str = (wchar_t *)str;
		len = ft_wstrlen(str);
		len = init_string_handler(data, len, &padding);
		(!data->flags[3]) ? pad(padding, padc) : ft_putnwstr_fd(str, len, 1);
		(data->flags[3]) ? pad(padding, padc) : ft_putnwstr_fd(str, len, 1);
	}
	else
	{
		str = (char *)str;
		len = ft_strlen(str);
		len = init_string_handler(data, len, &padding);
		(!data->flags[3]) ? pad(padding, padc) : ft_putnstr_fd(str, len, 1);
		(data->flags[3]) ? pad(padding, padc) : ft_putnstr_fd(str, len, 1);
	}
	if (padding > 0)
		return (len + padding);
	return (len);
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
	{
		data->index++;
		return (ft_putstr_fd("(null)", STDOUT));
	}
	len = process(format, data, str);
	data->index++;
	return (len);
}
