/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:41:20 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/09 19:28:29 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"
#include "../libft/libft.h"

static	void	funcinit(int (*func[20])(const char *, t_format_data *))
{
	func[0] = &hlenght;
	func[1] = &Hlenght;
	func[2] = &llenght;
	func[3] = &Llenght;
	func[4] = &jlenght;
	func[5] = &zlenght;
}

int		printformat(const char *format, t_format_data *data)
{
	int		option;
	int		(*func[20])(const char *, t_format_data *);

	funcinit(func);
	option = ft_strfindoc("hHlHjz", format[data->index]);
	return (option < 20) ? func[option](format, data) : (-1);
}
