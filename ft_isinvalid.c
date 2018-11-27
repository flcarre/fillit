/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinvalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:24:07 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/27 12:39:51 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_is(unsigned short *y, unsigned short mask[19][4])
{
}

int			ft_isinvalid(t_list **list)
{
	t_list			*l;
	unsigned short	mask[19][4];

	ft_set_mask(mask);
	l = *list;
	while (l)
	{
		if (ft_is((unsigned short *)(ft_lstipos((t_list *)l->content, \
			1))->content, mask))
		{
			ft_del_tetriminos(&(*list));
			return (1);
		}
		l = l->next;
	}
	return (0);
}
