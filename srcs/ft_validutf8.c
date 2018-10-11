/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validutf8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:44:47 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/11 12:56:36 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		test(size_t c)
{
	if (c <= 0x7FF)
		return (1);
	if (c >= 0xC280 && c <= 0xDFBF)
		return (2);
	if (c >= 0xE0A080 && c <= 0xE0BFBF)
		return (3);
	if (c >= 0xE18080 && c <= 0xECBFBF)
		return (3);
	if (c >= 0xED8080 && c <= 0xED9FBF)
		return (3);
	if (c >= 0xEE8080 && c <= 0xEFBFBF)
		return (3);
	if (c >= 0xF0908080 && c <= 0xF0BFBFBF)
		return (4);
	if (c >= 0xF1808080 && c <= 0xF3BFBFBF)
		return (4);
	if (c >= 0xF4808080 && c <= 0xF48FBFBF)
		return (4);
	return (0);
}

static size_t	convert(char *chara)
{
	size_t	utf8;

	if ((unsigned)chara[0] <= 0x7F)
	{
		utf8 = chara[0];
	}
	else if ((unsigned)chara[0] < 0xE0)
	{
		utf8 = chara[0];
		utf8 = (utf8 << 8) + chara[1];
	}
	else if ((unsigned)chara[0] < 0xF0)
	{
		utf8 = chara[0];
		utf8 = (utf8 << 8) + chara[1];
		utf8 = (utf8 << 8) + chara[2];
	}
	else
	{
		utf8 = chara[0];
		utf8 = (utf8 << 8) + chara[1];
		utf8 = (utf8 << 8) + chara[2];
		utf8 = (utf8 << 8) + chara[3];
	}
	return (utf8);
}

int			ft_validutf8(char *chara)
{
	size_t	utf8;

	utf8 = convert(chara);
	return (test(utf8));
}
