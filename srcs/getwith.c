/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getwith.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:09:46 by jfarinha          #+#    #+#             */
/*   Updated: 2018/03/09 13:29:25 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/project.h"

static void	getwidth(const char *format, t_format_data *data)
{
	if (ft_isdigit(format[data->index]))
	{
		data->fwidth = ft_atoi(&format[data->index]);
		while (ft_isdigit(format[data->index]))
			data->index++;
	}
	else
		data->fwidth = 0;
}
