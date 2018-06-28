/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 08:23:02 by jfarinha          #+#    #+#             */
/*   Updated: 2018/06/28 19:39:19 by jfarinha         ###   ########.fr       */
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
# define CONVERTIONS "sSdDipoOuUxXcC"
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
typedef unsigned int t_size;
typedef struct	s_fdata
{
	t_size		index;
	int			fwidth;
	int			len;
	int			preci;
	int			flags[5];
}				t_fdata;
typedef struct	s_nbdata
{
	intmax_t	nb;
	int			spad;
	int			sprc;
	int			snb;
	int			base;
	char		pad;
	char		poschar;
}				t_nbdata;
int				ft_printf(const char *format, ...);
int				string_handler(const char *format, t_fdata *data, va_list *ap);
int				char_handler(const char *format, t_fdata *data, va_list *ap);
int				int_handler(const char *format, t_fdata *data, va_list *ap);
void			pad(int lentopad, char c);
void			getdata(const char *format, t_fdata *data);
#endif
