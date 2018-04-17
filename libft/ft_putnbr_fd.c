/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:31:27 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/17 09:30:48 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int nbr, int fd)
{
	long	lnbr;
	size_t	len;
	char	nbra[11];

	lnbr = (long)nbr;
	len = 0;
	if (lnbr < 0)
	{
		lnbr *= -1;
		ft_putchar_fd('-', fd);
	}
	len = ft_uintmtoa(lnbr, 0, nbra) + 1;
	nbra[len] = '\0';
	ft_putstr_fd(nbra, fd);
	return ((nbr < 0) ? (len + 1) : len);
}
