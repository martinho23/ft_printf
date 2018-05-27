/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:32:58 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/23 14:59:19 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_wstrlen(const wchar_t *wstr)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		len += ft_wcharlen(wstr[i]);
		i++;
	}
	return (len);
}
