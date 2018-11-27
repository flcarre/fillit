/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinvalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:24:07 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/27 12:49:53 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_is(unsigned short *y, unsigned short mask[19][4])
{
	int n;

	n = -1;
	while (++n < 19)
	{
		while ((mask[n][0] & mask[n][2]) != mask[n][2])
		{
			if ((mask[n][0] & *y) == *y)
				return (0);
			if ((mask[n][0] & mask[n][1]) == mask[n][1])
			{
				mask[n][0] = mask[n][0] >> mask[n][3];
				mask[n][1] = mask[n][1] >> 4;
			}
			else
				mask[n][0] = mask[n][0] >> 1;
		}
		if ((mask[n][0] & *y) == *y)
			return (0);
	}
	return (1);
}

int			ft_isinvalid(t_list **list)
{
	t_list			*l;
	unsigned short	mask[19][4];

	l = *list;
	while (l)
	{
		ft_set_mask(mask);
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
