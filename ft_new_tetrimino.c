/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tetrimino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:06:28 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 18:24:53 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
static t_tet	*ft_lstvar_us(unsigned short us)
{
	t_tet			*tmp;

	if (!(tmp = ft_lstnew((const void *)&us, sizeof(unsigned short))))
		return ((void *)0);
	ft_lstenqueue(&tmp, ft_lstnew((const void *)&us, sizeof(unsigned short)));
	if (!(tmp->next))
	{
		ft_lstdel(&tmp, &ft_delcontent);
		return ((void *)0);
	}
	return (tmp);
}

static t_tet	*ft_lstvar(void)
{
	t_tet			*new;
	t_tet			*tmp;
	char			c;
	unsigned short	us;

	us = 0;
	c = 'A';
	if (!(tmp = ft_lstnew((const void *)&us, sizeof(unsigned short))))
		return ((void *)0);
	ft_lstenqueue(&tmp, (new = ft_lstnew((const void *)&c, sizeof(char))));
	if (!new)
	{
		ft_lstdel(&tmp, &ft_delcontent);
		return ((void *)0);
	}
	ft_lstenqueue(&tmp, (new = ft_lstvar_us(us)));
	if (!new)
	{
		ft_lstdel(&tmp, &ft_delcontent);
		return ((void *)0);
	}
	return (tmp);
}

static t_tet	*ft_lstparam(char *tetrimino)
{
	static int		i = 0;
	t_tet			*tmp;
	char			*c;

	if (!(tmp = ft_lstvar()))
		return ((void *)0);
	ft_strtobin(tetrimino, (unsigned short *)tmp->content);
	c = (char *)(ft_lstipos(tmp, 1))->content;
	*c += i;
	ft_measure_tetrimino((unsigned short *)tmp->content, \
	(unsigned short *)(ft_lstipos(tmp, 2))->content, \
	(unsigned short *)(ft_lstipos(tmp, 3))->content);
	i = (i < 26) ? i + 1 : 0;
	return (tmp);
}
*/


t_tet			*ft_new_tetrimino(char *tetrimino)
{
	t_tet			*new;
	static int i = 0;

	if (!(new = (t_tet *)malloc(sizeof(t_tet))))
		return ((void *)0);
	new->s = tetrimino;
	ft_strtobin(tetrimino, &(new->b));
	new->c = 'A' + i++;
	ft_measure_tetrimino(&(new->b), &(new->w), &(new->h));
	return (new);
	/*
	t_tet			*new;
	t_tet			*tmp;

	if (!(tmp = ft_lstnew((void *)0, 0)))
		return ((void *)0);
	tmp->content = (void *)tetrimino;
	tmp->content_size = ft_strlen((const char *)tetrimino) + 1;
	ft_lstenqueue(&tmp, (new = ft_lstparam(tetrimino)));
	if (!new)
	{
		ft_lstdel(&tmp, &ft_delcontent);
		return ((void *)0);
	}
	if (!(new = ft_lstnew((void *)0, 0)))
	{
		ft_lstdel(&tmp, &ft_delcontent);
		return ((void *)0);
	}
	new->content = (void *)tmp;
	new->content_size = sizeof(t_list) * 5 + ft_strlen(tetrimino) + 1 + \
						sizeof(unsigned short) * 3 + 1;
	return (new);*/
}
