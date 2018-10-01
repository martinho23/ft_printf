/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuprint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:08:25 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/01 13:36:10 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	proc(int size, int fd, const char *str, char *data[2][2])
{
	int		code;
	int		i;
	char	dest[size + 5];

	i = 0;
	while (*(str++) && i < size)
		if (ft_isprint(*(str - 1)))
			(dest[i++]) = *(str - 1);
		else if ((code = ft_getindice(data[CODE][UPRINT3], *(str - 1))) != -1)
		{
			ft_strncpy(&dest[i], &data[TEXT][UPRINT3][code * 5], 5);
			i += 5;
		}
		else if ((code = ft_getindice(data[CODE][UPRINT2], *(str - 1))) != -1)
		{
			ft_strncpy(&dest[i], &data[TEXT][UPRINT2][code * 4], 4);
			i += 4;
		}
	ft_strncpy(&dest[i], "[NULL]", 6);
	return (ft_putnstr_fd(dest, size, fd));
}

int			ft_putnuprint_fd(const char *str, int fd, int n)
{
	int		size;
	char	*uprint[2][2];

	if (fd < 0 || !str)
		return (-1);
	uprint[CODE][UPRINT3] = "\x01\x02\x03\x04\x05\x06\x07\x10\x11\x12\x13\x14\
\x15\x16\x17\x18\x1a\x1b\x7f";
	uprint[CODE][UPRINT2] = "\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x19\x1c\x1d\x1e\
\x1f";
	uprint[TEXT][UPRINT3] = "[SOH][STX][ETX][EOT][ENQ][ACK][BEL][DLE][DC1][DC2]\
[DC3][DC4][NAK][SYN][ETB][CAN][SUB][ESC][DEL]";
	uprint[TEXT][UPRINT2] = "[BS][HT][LF][VT][FF][CR][SO][SI][EM][FS][GS][RS]\
[US]";
	size = ft_uprintlen(str);
	size = (size < n) ? size : n;
	return (proc(size, fd, str, uprint));
}
