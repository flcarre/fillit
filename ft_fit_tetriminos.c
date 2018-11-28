/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:45:14 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 18:46:00 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_ipos(unsigned short mask[19][4], unsigned short x, \
			unsigned short *i)
{
	short			n;

	n = -1;
	while (++n < 19)
	{
		*i = 0;
		while ((mask[n][0] & x) != x && \
				(mask[n][0] & mask[n][2]) != mask[n][2])
		{
			(*i)++;
			mask[n][0] = mask[n][0] >> 1;
		}
		if ((mask[n][0] & x) != x)
			return ;
	}
}

static int	ft_fit(t_tet *e, unsigned short w, unsigned short h)
{
	char			*tmp;
	unsigned short	mask[19][4];
	unsigned short	i;
	unsigned short	n;

	if (!(tmp = ft_strnew(w * h)))
		return (1);
	ft_set_mask(mask);
	ft_ipos(mask, e->b, &i);
	n = 0;
	while (n < w * h)
	{
		ft_strncpy(tmp + n, (e->s) + i, (unsigned long)w);
		n += w;
		i += 4;
	}
	e->s = tmp;
	return (0);
}

int			ft_fit_tetriminos(t_tet *list)
{
	char *t;

	while (list)
	{
		t = list->s;
		if (ft_fit(list, list->w, list->h))
			return (1);
		free(t);
		list = list->next;
	}
	return (0);
}
