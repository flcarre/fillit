/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:58:23 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/28 17:50:47 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_square(char **tab, int size)
{
	if (!(*tab = ft_strnew(size * size + 1)))
		return (1);
	ft_memset((void *)*tab, (int)'.', (unsigned long)(size * size));
	return (0);
}

/*
static int	ft_max(t_list *l)
{
	int		max;
	unsigned short h;
	unsigned short w;

	max = 0;
	ft_putendl("1");
	while (l)
	{
		ft_putendl("1.1");
		h = *((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content);
		ft_putendl("1.2");
		w = *((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content);
		ft_putendl("2");
		max = ((unsigned short)max < w) ? (int)w : max;
		ft_putendl("3");
		max = ((unsigned short)max < h) ? (int)h : max;
		ft_putendl("4");
		l = l->next;
		ft_putendl("5");
	}
	ft_putendl("WTF");
	return (max);
}
*/

int			ft_solve(t_list *l, char **tab, int size)
{
//	if (ft_fit_tetriminos(l))
//		return (-1);
//	size = ft_max(l);
	if (ft_square(&(*tab), size))
		return (-1);
	while (!ft_backtracking(size, *tab, l))
	{
		free(*tab);
		*tab = (void *)0;
		size++;
		if (ft_square(&(*tab), size))
			return (-1);
	}
	return (size);
}
