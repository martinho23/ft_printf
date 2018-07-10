/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:21:05 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/10 20:13:34 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		percent_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;
	char	wc;

	(void)format;
	(void)ap;
	if (data->flags[0])
		wc = '0';
	else
		wc = ' ';
	len = (!data->flags[3]) ? pad(data->fwidth - 1, wc) : ft_putstr_fd("%", 1);
	len += (data->flags[3]) ? pad(data->fwidth - 1, wc) : ft_putstr_fd("%", 1);
	data->index++;
	return (len);
}
