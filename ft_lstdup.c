/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:59:17 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/13 17:10:15 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdup(t_list *list)
{
	t_list		*new;
	t_list		*elem;

	if (!list)
		return ((void *)0);
	new = (void *)0;
	while (list)
	{
		if (!(elem = ft_lstdupone(list)))
		{
			ft_lstdel(&new, &ft_delcontent);
			return ((void *)0);
		}
		ft_lstenqueue(&new, elem);
		list = list->next;
		elem = (void *)0;
	}
	return (new);
}
