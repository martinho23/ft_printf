/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 08:23:02 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/25 23:37:38 by jfarinha         ###   ########.fr       */
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

int				ft_isdigit(int c);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
int				ft_putchar_fd(int c, int fd);
int				ft_getindice(const char *str, char c);
int				ft_printf(const char *format, ...);
int				ft_putnstr_fd(const char *str, size_t n, int fd);
int				ft_putnwstr_fd(const wchar_t *str, size_t n, int fd);
int				string_handler(const char *format, t_fdata *data, va_list *ap);
int				char_handler(const char *format, t_fdata *data, va_list *ap);
void			pad(int lentopad, char c);
void			ft_bzero(void *p, t_size n);
void			*ft_memset(void *p, int c, size_t n);
void			getdata(const char *format, t_fdata *data);
size_t			ft_wcharlen(int c);
size_t			ft_strlen(const char *str);
size_t			ft_wstrlen(const wchar_t *wstr);
#endif
