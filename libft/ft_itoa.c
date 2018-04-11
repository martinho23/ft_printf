/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:26:44 by jfarinha          #+#    #+#             */
/*   Updated: 2018/03/29 18:28:49 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	process(int nbr, int step, char *array)
{
	int		size;

	size = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		array[step++] = '-';
	}
	if (nbr > 9)
		size = process((nbr / 10), (step + 1), array);
	array[size - step] = (nbr % 10) + '0';
	if (step >= size)
		return (step);
	return (size);
}

char		*ft_itoa(int nbr)
{
	char	array[12];
	int		size;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	size = process(nbr, 0, array);
	array[size] = '\0';
	return (ft_strdup(array));
}
