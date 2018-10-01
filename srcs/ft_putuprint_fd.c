/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuprint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:08:25 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/01 11:51:42 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_size(const char *str)
{
	int		i;

	i = 6;
	while(*str)
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

static int	proc(int size, int fd, const char *str)
{
	int		code;
	char	dest[size];
	char	*tmp;
	char	*char3;
	char	*char2;

	char3 = UPRINT3;
	char2 = UPRINT2;
	tmp = dest;
	while(*(str++))
		if (ft_isprint(*(str - 1)))
			*(tmp++) = *(str - 1);
		else if ((code = ft_getindice(UPRINT3CODE, *(str -1))) != -1)
		{
			ft_strncpy(tmp, &char3[code * 5], 5);
			tmp += 5;
		}
		else if ((code = ft_getindice(UPRINT2CODE, *(str - 1))) != -1)
		{
			ft_strncpy(tmp, &char2[code * 4], 4);
			tmp += 4;
		}
	ft_strncpy(tmp, "[NULL]", 6);
	return (ft_putnstr_fd(dest, size, fd));
}

int			ft_putuprint_fd(const char *str, int fd)
{
	int		size;

	if (fd < 0 || !str)
		return (-1);
	size = get_size(str);
	return (proc(size, fd, str));
}
