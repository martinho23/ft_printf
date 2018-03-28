/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 08:23:02 by jfarinha          #+#    #+#             */
/*   Updated: 2018/03/10 11:24:40 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PORJECT_H
# define FILL 0;
# define SHOWSIGNE 1;
# define CONVERSION 2;
# define LEFTADJUSTED 3;
# define SPACEINDICATOR 4;
typedef unsigned int t_size;
typedef struct	s_format_data
{
	t_size		fwidth;
	t_size		index;
	int			precision;
	int			flags[5];
}				t_format_data;

int				ft_printf(const char *format, ...);
static int		print_raw(const char *format, t_format_data *data);
static void		clean_flags(t_format_data *data);
static void		getflags(const char *format, t_format_data *data);
static void		process_flags(const char *format, t_format_data *data);
static void		getwidth(const char *format, t_format_data *data);
static void		getprecision(const char *format, t_format_data * data);

#endif
