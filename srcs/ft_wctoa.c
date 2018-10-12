/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:58:15 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/11 19:39:55 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_wctoa(char *s, size_t c)
{
	if (!s)
		return (0);
	if (c <= 0x7F)
		s[0] = c;
	else if (c <= 0x7FF)
	{
		s[0] = (c >> 6) + 0xc0;
		s[1] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		s[0] = (c >> 12) + 0xE0;
		s[1] = ((c >> 6) & 0x3F) + 0x80;
		s[2] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		s[0] = (c >> 18) + 0xF0;
		s[1] = ((c >> 12) & 0x3F) + 0x80;
		s[2] = ((c >> 6) & 0x3F) + 0x80;
		s[3] = (c & 0x3F) + 0x80;
	}
	else
		return (0);
	return (ft_validutf8(s));
}
