/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:51:01 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/14 15:13:07 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned long	i;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (*(needle + i) && *(haystack + i) == *(needle + i))
			i++;
		if (!(*(needle + i)))
			return ((char *)haystack);
		haystack++;
	}
	return ((void *)0);
}
