/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:17:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/10 01:19:08 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"
#include "../libft/libft.h"

int		ft_printf(const char *format, ...)
{
	t_fdata	data;
	int				count;
	int				tmpcnt;
	va_list			args;


	data.index = 0;
	count = 0;
	while (format[data.index])
	{
		if (format[data.index++] == '%' && format[data.index] != '%')
		{
			if ((tmpcnt = formathandler(format, &data, args)) == (-1))
				return (-1);
			else
				count += tmpcnt;
		}
		else
			count += printraw(format, &data);
	}
	return (count);
}
