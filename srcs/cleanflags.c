/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:55:15 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/09 19:52:47 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"

void	cleanflags(t_format_data *data)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		data->flags[i] = 0;
		i++;
	}
}
