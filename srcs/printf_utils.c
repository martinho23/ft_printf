/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:18:01 by jfarinha          #+#    #+#             */
/*   Updated: 2018/09/27 13:22:04 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

int		pad(t_fdata *data, int lentopad, char c)
{
	char	padding[PAD_MAX];
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (lentopad > 0)
	{
		while (i < lentopad && i < PAD_MAX)
			padding[i++] = c;
		write(data->fd, padding, i);
		count += i;
		i = 0;
		lentopad -= PAD_MAX;
	}
	return (count);
}

int		error_handler(int error, char *msg)
{
	if (error)
	{
		write(1, msg, ft_strlen(msg));
		return (1);
	}
	return (0);
}
