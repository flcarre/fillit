/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstipos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:33:29 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/03 18:25:48 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstipos(t_list *list, unsigned long i)
{
	if (!list)
		return ((void *)0);
	if (!i)
		return (list);
	return (ft_lstipos(list->next, i - 1));
}
