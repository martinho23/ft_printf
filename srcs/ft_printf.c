/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:17:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/11 19:15:56 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"

static int	formathandler()

int			ft_printf(const char *format, ...)
{
	t_fdata	data;
	int				rval;
	int				tmp;
	va_list			ap;


	data.index = 0;
	rval = 0;
	va_start(ap, format);
	while (format[data.index])
	{
		if (format[data.index++] == '%' && format[data.index] != '%')
			rval = ((tmp = formathandler(format, &data, &ap)) == -1) ? \
			(-1) : tmp + rval;
		else
			rval += printraw(format, &data);
	}
	va_end(ap);
	return (rval);
}
