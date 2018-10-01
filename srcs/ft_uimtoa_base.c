/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:52:42 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/29 20:39:35 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	proc(uintmax_t nbr, size_t b, char *ar, char *chars)
{
	int			size;

	size = 0;
	if (nbr > (b - 1))
	{
		size += proc((nbr / b), b, ar, chars);
	}
	ar[size] = chars[nbr % b];
	return (size + 1);
}

int			ft_uimtoa_base(uintmax_t nbr, size_t b, char *ar, char *cl)
{
	int		size;

	if (b < 2 || b > ft_strlen(cl))
		return (-1);
	size = proc(nbr, b, ar, cl);
	ar[size] = '\0';
	return (size);
}
