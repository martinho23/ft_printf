/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imtoalen_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:36:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/10 08:42:57 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_imtoalen_base(intmax_t nbr, size_t b)
{
	uintmax_t	unb;

	unb = (uintmax_t)(nbr < 0) ? (nbr * -1) : nbr;
	return (ft_uimtoalen_base(unb, b));
}
