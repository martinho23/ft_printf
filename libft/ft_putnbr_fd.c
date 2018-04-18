/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:31:27 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/18 09:39:51 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int nbr, int fd)
{
	long	lnbr;
	size_t	len;
	char	nbra[11];

	if (fd < 0)
		return (-1);
	lnbr = (long)nbr;
	len = 0;
	if (lnbr < 0)
	{
		lnbr *= -1;
		ft_putchar_fd('-', fd);
	}
	len = ft_uintmtoa_base(lnbr, 10, nbra);
	ft_putstr_fd(nbra, fd);
	return ((nbr < 0) ? (len + 1) : len);
}
