/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:08:50 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/14 15:33:00 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**tmp;
	unsigned long	w;
	unsigned long	i;

	if (!s)
		return ((void *)0);
	if (!(tmp = ft_strtabnew(ft_countword(s, c))))
		return ((void *)0);
	w = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (*(s + i) && *(s + i) != c)
			i++;
		if (*s)
			if (!(tmp[w++] = ft_strsub(s, 0, i)))
				return (ft_strtabdel(&tmp));
		s += i;
	}
	return (tmp);
}
