/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:31:27 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/20 13:31:29 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	long lnbr;

	lnbr = (long)nbr;
	if (lnbr < 0)
	{
		lnbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (lnbr > 9)
	{
		ft_putnbr_fd((lnbr / 10), fd);
	}
	ft_putchar_fd(((lnbr % 10) + '0'), fd);
}
