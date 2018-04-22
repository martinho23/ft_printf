/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 08:23:02 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/22 21:05:56 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PORJECT_H
# define FILL 0;
# define SHOWSIGNE 1;
# define CONVERSION 2;
# define LEFTADJUSTED 3;
# define SPACEINDICATOR 4;
# define FLAGS "0+#- "
# define LENGTHS "hHlLjz"
# define CONVERTIONS "sSpdDioOuUxXcC"
# include <stdarg.h>
# include <inttypes.h>
typedef unsigned int t_size;
typedef struct	s_fdata
{
	t_size		index;
	int			fwidth;
	int			len;
	int			precision;
	int			flags[5];
}				t_fdata;

int				ft_printf(const char *format, ...);
int				char_handler(const char *format, t_fdata *data, va_list *ap);
void			getdata(const char *format, t_fdata *data);
void			pad(int lentopad, char c);
#endif
