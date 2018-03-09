/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:55:15 by jfarinha          #+#    #+#             */
/*   Updated: 2018/03/09 13:03:27 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/project.h"

static void	clean_flags(t_format_data *data)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		data->flags[i] = 0;
		i++;
	}
}
