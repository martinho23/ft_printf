/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:18:01 by jfarinha          #+#    #+#             */
/*   Updated: 2018/05/10 12:36:38 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

void	pad(int lentopad, char c)
{
	char	padding[lentopad];
	int		i;

	i = 0;
	while (i < lentopad)
		padding[i++] = c;
	if (lentopad > 0)
		write(1, padding, (size_t)lentopad);
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
