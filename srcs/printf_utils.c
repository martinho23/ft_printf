/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:18:01 by jfarinha          #+#    #+#             */
/*   Updated: 2018/06/30 11:33:11 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void	pad(int lentopad, char c)
{
	char	padding[PAD_MAX];
	int		i;

	i = 0;
	while(lentopad > 0)
	{
		while (i < lentopad && i < PAD_MAX)
			padding[i++] = c;
		write(1, padding, i);
		i = 0;
		lentopad -= PAD_MAX;
	}
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
