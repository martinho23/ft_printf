/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoalen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:36:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/05 06:03:30 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

int		ft_uimtoalen_base(uintmax_t nbr, size_t b)
{
	int		i;

	if (b < 2)
		return (-1);
	if ((nbr % b) == 0)
		i = 2;
	else
		i = 1;
	while (nbr > b)
	{
		nbr /= b;
		i++;
	}
	return (i);
}
