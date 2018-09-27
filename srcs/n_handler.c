/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:16:04 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 11:30:02 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		n_handler(const char *format, t_fdata *data, va_list *ap)
{
	int		*n;
	(void)format;

	data->index++;
	n = va_arg(*ap, int*);
	*n = data->counter;
	return (0);
}
