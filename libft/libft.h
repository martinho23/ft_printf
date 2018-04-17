/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:28:51 by jfarinha          #+#    #+#             */
/*   Updated: 2018/04/17 09:07:53 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
/*
** List Structure
*/
typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
/*
** Memory Functions
*/
int				ft_memcmp(const void *p1, const void *p2, size_t n);
void			ft_bzero(void *p, size_t n);
void			ft_memdel(void **ap);
void			*ft_memset(void *p, int c, size_t n);
void			*ft_memchr(const void *p, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memalloc(size_t size);
/*
** String functions
*/
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_strfindoc(const char *str, char oc);
void			ft_strdel(char **ap);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char			*ft_strsub(const char *str, unsigned int start, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strfreejoin(char *s1, const char *s2);
char			*ft_strtrim(const char *str);
char			**ft_strsplit(const char *str, char c);
/*
** Char test functions
*/
int				ft_isdigit(int c);
int				ft_isspace(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_getindice(const char *str, char c);
/*
** Transform char*
*/
int				ft_toupper(int c);
int				ft_tolower(int c);
/*
** Print functions
*/
size_t			ft_putchar(int c);
size_t			ft_putstr(const char *str);
size_t			ft_putendl(const char *str);
size_t			ft_putnbr(int nbr);
size_t			ft_putchar_fd(int c, int fd);
size_t			ft_putstr_fd(const char *str, int fd);
size_t			ft_putendl_fd(const char *str, int fd);
size_t			ft_putnbr_fd(int nbr, int fd);
/*
** Misc functions
*/
int				ft_atoi(const char *str);
char			*ft_itoa(int nbr);
size_t			ft_uintmtoa(uintmax_t nbr, size_t step, char *array);
/*
**List functions
*/
t_list			*ft_lstnew(const void *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *element));
void			ft_lstdelone(t_list **a_lst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **a_list, void (*del)(void*, size_t));
void			ft_lstadd(t_list **a_lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *element));
#endif
