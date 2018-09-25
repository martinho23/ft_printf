/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 04:01:54 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/25 15:37:56 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putnwstr_fd(const wchar_t *str, size_t n, int fd)
{
	int len;

	if (fd > 0 && str)
	{
		len = 0;
		while (*str && ((long int)n > (long int)len))
			len += ft_putchar_fd(*str++, fd);
		return (len);
	}
	return (-1);
}
