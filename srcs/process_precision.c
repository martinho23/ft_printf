/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:32:22 by jfarinha          #+#    #+#             */
/*   Updated: 2018/01/26 23:17:39 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"
#include "../libft/libft.h"

static void	process_precision(char *format, t_format_data *data)
{
	if (format[data->index] == '.')
	{
		data->index++;
		data->precision = ft_atoi(&format[data->index]);
		while (ft_isdigit(format[data->index]))
			data->index++;
	}
	else
		data->precision = 6;
}
