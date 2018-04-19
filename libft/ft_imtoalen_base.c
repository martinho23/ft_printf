/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoalen_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:36:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/19 12:05:30 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_imtoalen_base(intmax_t nbr, int b)
{
	int		i;

	i = 1;
	if (b < 2)
		return (-1);
	nbr = (nbr < 0) ? (nbr * -1) : nbr;
	while (nbr > b)
	{
		nbr /= b;
		i++;
	}
	return (i);
}
