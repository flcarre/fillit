/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:28:54 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/13 15:15:23 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, unsigned long))
{
	if (!(*alst) || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)&(*alst));
	*alst = (void *)0;
}
