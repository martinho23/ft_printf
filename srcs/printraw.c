/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:22:37 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/09 19:51:43 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"
#include <unistd.h>

int		printraw(const char *format, t_format_data *data)
{
	int		i;

	i = 0;
	while (format[data->index + i] && format[data->index + i] != '%')
		i++;
	write(1, &format[data->index], i);
	data->index += i;
	return (i);
}
