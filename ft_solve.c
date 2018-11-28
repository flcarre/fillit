/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:58:23 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/28 21:02:01 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_square(char **tab, int size)
{
	*tab = ft_strnew(size * size + 1);
	ft_memset((void *)*tab, (int)'.', (unsigned long)(size * size));
}

static int	ft_max(t_tet *l)
{
	int		max;

	max = 0;
	while (l)
	{
		max = ((unsigned short)max < l->w) ? (int)l->w : max;
		max = ((unsigned short)max < l->h) ? (int)l->h : max;
		l = l->next;
	}
	return (max);
}

int			ft_solve(t_tet *l, char **tab)
{
	int		size;

	if (ft_fit_tetriminos(l))
		return (-1);
	size = ft_max(l);
	ft_square(&(*tab), size);
	while (!ft_backtracking(size, *tab, l))
	{
		free(*tab);
		*tab = (void *)0;
		size++;
		ft_square(&(*tab), size);
	}
	return (size);
}
