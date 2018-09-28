/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuprint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:08:25 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 17:58:56 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_size(const char *str)
{
	int		i;

		i = 5;
	while(str)
	{
		if (*str < 8 || (*str > 15 && *str < 28))
			i += 5;
		else if ((*str < 16) || (*str > 28 && *str < 33))
			i += 4;
		else
			i++;
		str++;
	}
	return (i);
}

static int	proc(int size, int fd, const char *str)
{
	char	dest[size];
	char	*tmp;
	char	*char3;
	char	*char2;

	char3 = UPRINT3;
	char2 = UPRINT2;
	tmp = dest;
	while(str)
	{
		if (ft_getindice(*str, UPRINT3CODE))
	}
}

int			ft_putuprint_fd(const char *str, int fd)
{
	int		size;

	if (fd < 0)
		return (-1);
	size = get_size(str);
	return (proc(size, fd, str));
}
