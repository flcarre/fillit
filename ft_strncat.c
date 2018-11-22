/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:24:01 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/14 15:54:10 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, unsigned long n)
{
	unsigned long	i;
	char			*s;

	if (!n)
		return (s1);
	i = 0;
	s = s1 + ft_strlen((const char *)s1);
	while (*(s2 + i) && i < n)
	{
		*(s + i) = *(s2 + i);
		i++;
	}
	*(s + i) = '\0';
	return (s1);
}
