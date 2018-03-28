/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:17:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/03/10 11:33:03 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"
#include "../libft/libft.h"

int		ft_printf(const char *format, ...)
{
	t_format_data	data;
	int				count;

	data.index = 0;
	count = 0;
	while (format[data.index])
	{
		if (format[data.index++] == '%' && format[data.index] != '%')
		{
			getflags(format, &data);
			getwidth(format, &data);
			getprecision(format, &data);
		}
		else
			count += print_raw(format, &data);
	}
	return (count);
}
