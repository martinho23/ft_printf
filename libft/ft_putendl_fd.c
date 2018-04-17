/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:22:15 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/17 08:46:32 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putendl_fd(const char *str, int fd)
{
	size_t len;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
	}
	return (len +1);
}
