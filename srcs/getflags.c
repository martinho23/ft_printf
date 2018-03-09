/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:19:57 by jfarinha          #+#    #+#             */
/*   Updated: 2018/03/09 13:30:48 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"
#include "../libft/libft.h"

static void	getflags(const char *format, t_format_data *data)
{
	int		flag_code;

	clean_flags(data);
	while (flag_code = ft_getindice("0+#- ", format[data->index]) < 0)
	{
		data->flags[flag_code] = 1;
		data->index++;
	}
}
