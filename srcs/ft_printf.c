/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:17:36 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/13 13:10:12 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "../includes/project.h"

static int	printraw(const char *format, t_fdata *data)
{
	int		i;

	i = 0;
	while (format[data->index + i] && format[data->index + i] != '%')
		i++;
	write(1, &format[data->index], i);
	data->index += i;
	return (i);
}

static	void	funcinit(int (*func[14])(const char *, t_fdata *))
{
}

int		printformat(const char *format, t_fdata *data, va_list *ap)
{
	int		option;
	int		(*func[20])(const char *, t_fdata *);

	funcinit(func);
	option = ft_strfindoc(CONVERTIONS, format[data->index]);
	return (option < 20) ? func[option](format, data) : (-1);
}

int			ft_printf(const char *format, ...)
{
	t_fdata	data;
	int				rval;
	int				tmp;
	va_list			ap;


	data.index = 0;
	rval = 0;
	va_start(ap, format);
	while (format[data.index])
	{
		if (format[data.index++] == '%' && format[data.index] != '%')
			rval = ((tmp = printformat(format, &data, &ap)) == -1) ? \
			(-1) : tmp + rval;
		else
			rval += printraw(format, &data);
	}
	va_end(ap);
	return (rval);
}
