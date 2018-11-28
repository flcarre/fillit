/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:13 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/28 19:14:06 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isfree(int size, char *tab, t_tet *l, int i)
{
	unsigned short	n[3];

	n[2] = 1;
	n[0] = 0;
	if (tab[i] == '.' || (n[2] = 0))
	{
		n[1] = 0;
		while (n[1] < l->w * l->h)
		{
			n[0] += (!(n[1] % l->w) && n[1]) ? size : 0;
			n[2] = (tab[i + n[0]] == '.' && (l->s)[n[1]] == '#') ? 1 : n[2];
			n[2] = (tab[i + n[0]] != '.' && (l->s)[n[1]] == '#') ? 0 : n[2];
			if (!n[2])
				return (0);
			n[1]++;
		}
	}
	return ((int)n[2]);
}

static void	ft_place(int size, char *tab, t_tet *l, int i)
{
	unsigned short	n[2];
	char			c;

	c = l->c;
	n[1] = 0;
	n[0] = 0;
	while (n[1] < l->w * l->h)
	{
		n[0] += (!(n[1] % l->w) && n[1]) ? size : 0;
		tab[i + n[0]] = (tab[i + n[0]] == '.' && (l->s)[n[1]] == '#') ? c : '.';
		n[1]++;
	}
}

static void	ft_reset(int size, char *tab, t_tet *l, int i)
{
	unsigned short	n[2];

	n[1] = 0;
	n[0] = 0;
	while (n[1] < l->w * l->h)
	{
		n[0] += (!(n[1] % l->w) && n[1]) ? size : 0;
		tab[i + n[0]] = ((l->s)[n[1]] == '#') ? '.' : tab[i + n[0]];
		n[1]++;
	}
}

int			ft_backtracking(int size, char *tab, t_tet *l)
{
	int			i;

	if (!l)
		return (1);
	i = 0;
	while (tab[i])
	{
		if (ft_isfree(size, tab, l, i))
		{
			ft_place(size, tab, l, i);
			if (ft_backtracking(size, tab, l->next))
				return (1);
			ft_reset(size, tab, l, i);
		}
		i++;
	}
	return (0);
}
