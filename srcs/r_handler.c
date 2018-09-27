/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:08:25 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 16:54:30 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_size(char *str)
{
	int		i;

		i = 5;
	while(str)
	{
		if (*str < 8 || (*str > 15 && *str < 28))
			i += 5;
		else if ((*str < 16) || (*str > 28 && *str < 33))
			i += 4;
		else
			i++;
		str++;
	}
	return (i);
}

int		r_handler(const char *format, t_fdata *data, va_list *ap)
{

	return (0);
}
