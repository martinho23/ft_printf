/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:13:59 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/11 20:14:19 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

int				ft_putwchar_fd(int c, int fd)
{
	char	s[4];
	int		size;

	if (fd < 0)
		return (-1);
	size = ft_wctoa(s, c);
	write(fd, s, size);
	return ((size) ? size : -1);
}
