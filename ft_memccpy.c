/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:08:37 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/14 14:49:09 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, unsigned long n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*start;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	start = (unsigned char *)src;
	while ((unsigned long)(s - start) < n)
	{
		*(d++) = *s;
		if (*s == (unsigned char)c)
			return ((void *)d);
		s++;
	}
	return ((void *)0);
}
