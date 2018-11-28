/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:45:14 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 15:07:28 by lutsiara         ###   ########.fr       */
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

static int	ft_fit(t_list *e, unsigned short w, unsigned short h)
{
	char			*tmp;
	unsigned short	mask[19][4];
	unsigned short	i;
	unsigned short	n;

	if (!(tmp = ft_strnew(w * h)))
		return (1);
	ft_set_mask(mask);
	ft_ipos(mask, *((unsigned short *)(ft_lstipos(e, 1))->content), &i);
	n = 0;
	while (n < w * h)
	{
		ft_strncpy(tmp + n, (const char *)(((ft_lstipos(e, 0))->content) + i), \
		(unsigned long)w);
		n += w;
		i += 4;
	}
	(ft_lstipos(e, 0))->content = (void *)tmp;
	(ft_lstipos(e, 0))->content_size = w * h + 1;
	return (0);
}

int			ft_fit_tetriminos(t_list *list)
{
	char			*t;
	unsigned short	w;
	unsigned short	h;

	while (list)
	{
		t = (char *)(ft_lstipos((t_list *)list->content, 0))->content;
		w = *((unsigned short *)(ft_lstipos((t_list \
			*)list->content, 3))->content);
		h = *((unsigned short *)(ft_lstipos((t_list \
			*)list->content, 4))->content);
		if (ft_fit((t_list *)list->content, w, h))
			return (1);
		free(t);
		list = list->next;
	}
	return (0);
}
