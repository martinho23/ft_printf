/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuprint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:08:25 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/01 13:09:42 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_uprintlen(const char *str)
{
	int		i;

	i = 6;
	while (*str)
	{
		if (*str != 25 && (*str == 127 || *str < 8 || (*str > 15 && *str < 28)))
			i += 5;
		else if (*str == 25 || (*str < 16) || *str < 32)
			i += 4;
		else
			i++;
		str++;
	}
	return (i);
}
