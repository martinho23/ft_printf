/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:21:05 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/12 17:36:41 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		percent_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	char	wc;

	(void)format;
	(void)ap;
	if (format[data->index] == '%')
	{
		if (data->flags[0])
			wc = '0';
		else
			wc = ' ';
		len = (!data->flags[3]) ? pad(data->fwidth - 1, wc) : ft_putstr_fd("%", 1);
		len += (data->flags[3]) ? pad(data->fwidth - 1, wc) : ft_putstr_fd("%", 1);
			data->index++;
	}
	else
		len = ft_putchar_fd('%', 1);
	return (len);
}
