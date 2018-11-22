/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:29:35 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/13 16:50:44 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ltmp;
	t_list		*nelem;

	if (!lst || !f)
		return ((void *)0);
	ltmp = (void *)0;
	while (lst)
	{
		if (!(nelem = f(lst)))
		{
			ft_lstdel(&ltmp, &ft_delcontent);
			return ((void *)0);
		}
		ft_lstenqueue(&ltmp, nelem);
		lst = lst->next;
		nelem = (void *)0;
	}
	return (ltmp);
}
