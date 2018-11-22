/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:25:10 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/14 14:35:04 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned long n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*start;

	if (!n)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	start = (unsigned char *)src;
	while ((unsigned long)(s - start) < n)
		*(d++) = *(s++);
	return (dst);
}
