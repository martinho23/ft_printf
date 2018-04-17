/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:52:42 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/17 09:08:33 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uintmtoa(uintmax_t nbr, size_t step, char *array)
{
	size_t	size = 0;

	size = (step > size) ? step : size;
	if (nbr > 9) {
		size = ft_uintmtoa((nbr / 10), (step + 1), array);
	}
	array[size - step] = (nbr % 10) + '0';
	return (size);
}
