/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstenqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:43:40 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/18 17:38:22 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstenqueue(t_list **list, t_list *elem)
{
	t_list		*i;

	if (!elem)
		return ;
	if (!list || !(*list))
	{
		(*list) = elem;
		return ;
	}
	i = (*list);
	while (i->next)
		i = i->next;
	i->next = elem;
}
