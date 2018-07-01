/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:12:10 by jfarinha          #+#    #+#             */
/*   Updated: 2018/07/01 15:09:23 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	*ft_memset(void *p, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)p;
	while (n-- > 0)
		*(tmp++) = (unsigned char)c;
	return (p);
}
