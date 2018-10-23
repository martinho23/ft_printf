/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 04:01:54 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/23 12:30:59 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

int		ft_putnwstr_fd(const wchar_t *str, size_t n, int fd)
{
	int				len;
	int				rcode;
	unsigned char	put[ft_wstrlen(str)];

	if (fd > 0 && str)
	{
		len = 0;
		rcode = 0;
		while (*str)
		{
			rcode = ft_wctoa(&put[len], *str++);
			if (!rcode)
				return (-1);
			if ((long int)(rcode + len) > (long int)n)
				break ;
			len += rcode;
		}
		write(fd, put, len);
		return (len);
	}
	return (-1);
}
