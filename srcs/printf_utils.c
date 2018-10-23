/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:18:01 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/23 12:32:11 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

int			pad(t_fdata *data, int lentopad, char c)
{
	char	padding[PAD_MAX];
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (lentopad > 0)
	{
		while (i < lentopad && i < PAD_MAX)
			padding[i++] = c;
		write(data->fd, padding, i);
		count += i;
		i = 0;
		lentopad -= PAD_MAX;
	}
	return (count);
}

uintmax_t	getuim(const char *format, t_fdata *data, va_list *ap)
{
	if (format[data->index] == 'p')
		return ((uintmax_t)va_arg(*ap, void *));
	else if (data->len == 0)
		return ((short unsigned int)va_arg(*ap, uintmax_t));
	else if (data->len == 1)
		return ((unsigned char)va_arg(*ap, uintmax_t));
	else if (data->len == 2)
		return ((unsigned long int)va_arg(*ap, uintmax_t));
	else if (data->len == 3)
		return ((unsigned long long int)va_arg(*ap, uintmax_t));
	else if (data->len == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (data->len == 5)
		return ((size_t)va_arg(*ap, uintmax_t));
	else
		return ((unsigned int)va_arg(*ap, uintmax_t));
}
