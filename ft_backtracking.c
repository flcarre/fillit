/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:13 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/29 14:23:08 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isfree(int size, char *tab, t_tet *e, int i)
{
	int n;
	unsigned short bin;
	unsigned short x;

	x = e->w * e->h;
	bin = 0;
	n = 0;
	while (n < e->w * e->h && i % size + n % e->w < size)
	{
		x--;
		if (tab[i + n % e->w] != '.' && (e->s)[n] != '.')
			bin += (unsigned short)ft_paw(2, (unsigned int)x);
		n++;
		if (n % e->w == 0)
			i += size;
	}
	if ((i % size) + (n % e->w) < size)
	{
		if(bin == 0)
			return (1);
	}
	return(0);
}

static void	ft_place(int size, char *tab, t_tet *e, int i)
{
	int n;

	n = 0;
	while (n < e->w * e->h)
	{
		if ((e->s)[n] == '#')
			tab[i + n % e->w] = e->c;
		n++;
		if (n % e->w == 0)
			i += size;
	}
}

static void	ft_reset(int size, char *tab, t_tet *e, int i)
{
	int n;

	n = 0;
	while (n < e->w * e->h)
	{
		if ((e->s)[n] == '#')
			tab[i + n % e->w] = '.';
		n++;
		if (n % e->w == 0)
			i += size;
	}
}

int			ft_backtracking(int size, char *tab, t_tet *l)
{
	int			i;

	if (!l)
		return (1);
	i = 0;
	while (i < size * size && i / size + l->h <= size)
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
