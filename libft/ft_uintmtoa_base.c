/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:52:42 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/18 09:38:11 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	proc(uintmax_t nbr, size_t b, int step, char *ar, char *chars)
{
	int	size;

	if (b < 2 || b > 36)
		return (-1);
	size = 0;
	size = (step > size) ? step : size;
	if (nbr > (b - 1))
		size = proc((nbr / b), b, (step + 1), ar, chars);
	ar[size - step] = chars[nbr % b];
	return (size);
}

int			ft_uintmtoa_base(uintmax_t nbr, size_t b, char *ar)
{
	char	chars[36];
	int		i;

	i = 0;
	while (i++ < 10)
		chars[i - 1] = (char)('0' + (i - 1));
	i = 0;
	while (i++ < 26)
		chars[(i - 1) + 10] = (char)('A' + (i - 1));
	i = proc(nbr, b, 0, ar, chars);
	ar[i + 1] = '\0';
	return (i + 1);
}
