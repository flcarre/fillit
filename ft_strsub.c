/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:31:06 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/12 17:06:00 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, unsigned long len)
{
	char			*tmp;
	unsigned long	i;

	if (!(tmp = ft_strnew(len)))
		return ((void *)0);
	if (!s)
		return (tmp);
	i = 0;
	while (len--)
		*(tmp + (i++)) = *((s++) + start);
	return (tmp);
}
