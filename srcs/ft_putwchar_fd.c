/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:13:59 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/23 12:31:46 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

int		ft_putwchar_fd(int c, int fd)
{
	unsigned char	s[4];
	int				size;

	if (fd < 0)
		return (-1);
	size = ft_wctoa(s, c);
	if (!size)
		return (-1);
	write(fd, s, size);
	return (size);
}
