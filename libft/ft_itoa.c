/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:26:44 by jfarinha          #+#    #+#             */
/*   Updated: 2018/01/27 14:36:49 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	process(int nbr, int step, char *array)
{
	long	lnbr;
	int		size;

	lnbr = (long)nbr;
	size = 0;
	if (lnbr < 0)
	{
		lnbr *= -1;
		array[step++] = '-';
	}
	if (lnbr > 9)
		size = process((lnbr / 10), (step + 1), array);
	array[size - step] = (lnbr % 10) + '0';
	if (step >= size)
		return (step);
	return (size);
}

char		*ft_itoa(int nbr)
{
	char	array[12];
	int		size;

	size = process(nbr, 0, array);
	array[size] = '\0';
	return (ft_strdup(array));
}
