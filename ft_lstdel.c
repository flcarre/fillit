/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:20:51 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/13 15:11:18 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, unsigned long))
{
	if (!(*alst) || !del)
		return ;
	ft_lstdel(&((*alst)->next), del);
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)&(*alst));
	*alst = (void *)0;
}
