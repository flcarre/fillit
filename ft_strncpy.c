/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:42:30 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/14 15:00:59 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dst, const char *src, unsigned long len)
{
	unsigned long	i;

	if (!len)
		return (dst);
	i = 0;
	while (*src && i < len)
		*(dst + (i++)) = *(src++);
	while (i < len)
		*(dst + (i++)) = '\0';
	return (dst);
}
