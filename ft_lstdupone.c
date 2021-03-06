/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:52:11 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/13 16:57:11 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdupone(t_list *elem)
{
	t_list		*new;

	if (!elem)
		return ((void *)0);
	if (!(new = ft_lstnew((void const *)elem->content, elem->content_size)))
		return ((void *)0);
	return (new);
}
