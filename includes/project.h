/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 08:23:02 by jfarinha          #+#    #+#             */
/*   Updated: 2018/01/26 23:03:20 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PORJECT_H
# define BUFF_MAX 1024
typedef unsigned int t_size;
typedef struct	s_format_data
{
	t_size		index;
	t_size		fwidth;
	t_size		precision;
	t_size		arindex;
	int			leftadjusted;
	char		intar[21];
}				t_format_data;

	int			ft_printf(const char *format, ...);
	static int	is_left_adjusted(char *format, t_format_data *data);
	static void	process_fwidth(char *format, t_format_data *data);
	static void	process_precision(char *format, t_format_data * data);
	static void	process_flags(char *format, t_format_data *data);

#endif
