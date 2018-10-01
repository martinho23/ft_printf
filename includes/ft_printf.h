/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 08:23:02 by jfarinha          #+#    #+#             */
/*   Updated: 2018/10/01 11:40:24 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STDOUT 1
# define FLAGS "0+#- "
# define LENGTHS "hHlLjz"
# define CONVERTIONS "sSdDipoOuUxXcC%bn"
# define PAD_MAX 1000
# define CNVN 18
# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16_C "0123456789ABCDEF"
# define UPRINT3 "[SOH][STX][ETX][EOT][ENQ][ACK][BEL][DLE][DC1][DC2][DC3][DC4]\
[NAK][SYN][ETB][CAN][SUB][ESC][DEL]"
# define UPRINT2 "[BS][HT][LF][VT][FF][CR][SO][SI][EM][FS][GS][RS][US]"
# define UPRINT3CODE "\x01\x02\x03\x04\x05\x06\x07\x10\x11\x12\x13\x14\x15\x16\
\x17\x18\x1a\x1b\x7f"
# define UPRINT2CODE "\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f\x19\x1c\x1d\x1e\x1f"
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

typedef unsigned int	t_size;
typedef struct	s_fdata
{
	t_size		index;
	int			counter;
	int			fd;
	int			fwidth;
	int			len;
	int			preci;
	int			flags[5];
}				t_fdata;
typedef struct	s_nbdata
{
	intmax_t	nb;
	uintmax_t	unb;
	int			spad;
	int			sprc;
	int			snb;
	size_t		base;
	char		pad;
	char		poschar;
	char		*conv;
}				t_nbdata;
/*
** ========== Ft_Printf ==========
*/
int				ft_printf(const char *format, ...);
int				n_handler(const char *format, t_fdata *data, va_list *ap);
int				r_handler(const char *format, t_fdata *data, va_list *ap);
int				int_handler(const char *format, t_fdata *data, va_list *ap);
int				char_handler(const char *format, t_fdata *data, va_list *ap);
int				uint_handler(const char *format, t_fdata *date, va_list *ap);
int				string_handler(const char *format, t_fdata *data, va_list *ap);
int				percent_handler(const char *format, t_fdata *data, va_list *ap);
int				pad(t_fdata *data, int lentopad, char c);
void			getdata(const char *format, t_fdata *data, va_list *ap);
/*
** ========== Lib FT ==========
*/
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_atoi(const char *str);
int				ft_putchar_fd(int c, int fd);
int				ft_putstr_fd(const char *str, int fd);
int				ft_putuprint_fd(const char *str, int fd);
int				ft_getindice(const char *str, char c);
int				ft_imtoalen_base(intmax_t nbr, size_t b);
int				ft_uimtoalen_base(uintmax_t nbr, size_t b);
int				ft_putnstr_fd(const char *str, size_t n, int fd);
int				ft_putnwstr_fd(const wchar_t *wstr, size_t n, int fd);
int				ft_uimtoa_base(uintmax_t nbr, size_t b, char *ar, char *cl);
char			*ft_strstr(const char *str1, const char *str2);
char			*ft_strncpy(char *dest, const char *src, size_t n);
void			ft_bzero(void *p, size_t n);
void			*ft_memset(void *p, int c, size_t n);
size_t			ft_wcharlen(int c);
size_t			ft_strlen(const char *str);
size_t			ft_wstrlen(const wchar_t *str);
#endif
