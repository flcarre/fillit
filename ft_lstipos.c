/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstipos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:33:29 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 17:16:23 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstipos(t_list *list, unsigned long i)
{
	if (!list)
	{
		ft_putendl(".1");
		return ((void *)0);
	}
	if (!i)
	{
		ft_putendl(".2");

		return (list);
	}
	ft_putendl(".3");
	return (ft_lstipos(list->next, i - 1));
}
