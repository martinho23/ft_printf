/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 07:21:05 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/05 06:31:22 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		percent_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		len;

	(void)format;
	(void)ap;
	len = (!data->flags[3]) ? pad(data->fwidth - 1, ' ') : ft_putstr_fd("%", 1);
	len += (data->flags[3]) ? pad(data->fwidth - 1, ' ') : ft_putstr_fd("%", 1);
	data->index++;
	return (len);
}
