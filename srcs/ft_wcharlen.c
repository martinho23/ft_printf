/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:27:28 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/01 14:51:23 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_wcharlen(int c)
{
	if (c <= 0x7F)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	if (c <= 0x10FFFF)
		return (4);
	return (-1);
}
