/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:44:25 by jfarinha          #+#    #+#             */
/*   Updated: 2017/11/21 09:28:27 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	nbr_to_char(long nbr, char *tmp)
{
	long long	l_nbr;

	l_nbr = (long)nbr;
	if (l_nbr == 0)
		*(tmp++) = '0';
	while (l_nbr != 0)
	{
		if (l_nbr > 9)
		{
			*(tmp++) = (l_nbr % 10) + '0';
			l_nbr = l_nbr / 10;
		}
		else if (l_nbr < 0)
			l_nbr *= -1;
		else
		{
			*(tmp++) = l_nbr + '0';
			l_nbr = 0;
		}
	}
	*tmp = '\0';
}

static	char	*alloc(int nbr, char *tmp)
{
	char	*ret_val;
	int		len;
	int		is_neg;
	int		i;

	i = 0;
	is_neg = 0;
	len = ft_strlen(tmp);
	if (nbr < 0)
		is_neg = 1;
	if (!(ret_val = (char *)malloc(sizeof(*ret_val) * (len+ 1 + is_neg))))
		return (NULL);
	if (nbr < 0)
		ret_val[i++] = '-';
	while (tmp[i - is_neg])
	{
		ret_val[i] = tmp[(len - 1) - (i - is_neg)];
		i++;
	}
	ret_val[i] = '\0';
	return (ret_val);
}

char			*ft_itoa(int nbr)
{
	char	tmp[11];
	char	*ret_val;

	nbr_to_char(nbr, tmp);
	ret_val = alloc(nbr, tmp);
	return (ret_val);
}
