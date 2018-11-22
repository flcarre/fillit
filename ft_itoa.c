/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:09:13 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/21 16:47:37 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	i;
	int				x;
	char			*tmp;

	i = ft_digitlen(n, 10);
	if (!(tmp = ft_strnew((unsigned long)i)))
		return ((void *)0);
	*tmp = (n < 0) ? '-' : '\0';
	x = n;
	while ((n < 0) ? (--i) : (i--))
	{
		*(tmp + i) = '0' + ft_abs((long)(x % 10));
		x /= 10;
	}
	return (tmp);
}
