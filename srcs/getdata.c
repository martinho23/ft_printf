/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:50:55 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/11 20:16:22 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/project.h"
#include "../libft/libft.h"

static void	getflags(const char *format, t_fdata *data)
{
	int		flag_code;

	while ((flag_code = ft_getindice(FLAGS, format[data->index])) < 0)
	{
		data->flags[flag_code] = 1;
		data->index++;
	}
}

static void	getprecison(const char *format, t_fdata *data)
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

static void	getwidth(const char *format, t_fdata *data)
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

static void	getlength(const char *format, t_fdata *data)
{
	if ((data->length = ft_getindice(LENGTHS, format[data->index])) < 0)
	{
		data->index++;
		if ((format[data->index - 1] == 'l' && format[data->index] == 'l') ||\
			(format[data->index - 1] == 'h' && format[data->index] == 'h'))
		{
			data->length++;
			data->index++;
		}
	}
}

void		getdata(const char *format, t_fdata *data)
{
	ft_bzero(&data->index, sizeof(t_fdata) - sizeof(data->index));
	getflags(format, data);
	getwidth(format, data);
	getprecison(format, data);
	getlength(format, data);
}
