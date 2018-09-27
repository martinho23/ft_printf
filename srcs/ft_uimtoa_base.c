/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:52:42 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 10:36:12 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	proc(uintmax_t nbr, size_t b, char *ar, char *chars)
{
	static int	step = 0;
	int			size;

	size = step;
	if (nbr > (b - 1))
	{
		step++;
		size = proc((nbr / b), b, ar, chars);
		step--;
	}
	ar[size - step] = chars[nbr % b];
	return (size);
}

int			ft_uimtoa_base(uintmax_t nbr, size_t b, char *ar, char *cl)
{
	int		size;

	if (b < 2 || b > ft_strlen(cl))
		return (-1);
	size = proc(nbr, b, ar, cl);
	ar[size + 1] = '\0';
	return (size + 1);
}
