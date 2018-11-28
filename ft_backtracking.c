/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:13 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/28 23:40:24 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isfree(int size, char *tab, t_tet *e, int i)
{
	int n;
	unsigned short bin;
	unsigned short newbin;
	char *tmp;

	newbin = 0;
	bin = 0;
	n = 0;
	tmp = ft_strnew(e->w * e->h);
	while (n < e->w * e->h && i + e->w * e->h < size * size)
	{
		tmp[n] = tab[i];
		n++;
		printf("n = %d w = %d\n", n, (int)e->w);
		if (n % e->w == 0)
		{
			i += size;
		}
		else
			i++;
	}
	ft_strtobin2(tmp, &newbin, (int)(e->w * e->h));
	ft_strtobin2(e->s, &bin, (int)(e->w * e->h));
	printf("new = %x ///// bin =%x\n", newbin, bin);
	printf("newstr = %s ///// str =%s\n", tmp, e->s);
	free(tmp);
	if((bin ^ newbin) == bin)
	{
		printf("____________________________\n");
		return (1);
	}
	return(0);
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
		tab[i + n[0]] = (tab[i + n[0]] == '.' && (l->s)[n[1]] == '#') ? c : '.';
		n[0] += (!(n[1] % l->w) && n[1]) ? size : 1;
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
		tab[i + n[0]] = ((l->s)[n[1]] == '#') ? '.' : tab[i + n[0]];
		n[0] += (!(n[1] % l->w) && n[1]) ? size : 1;
		n[1]++;
	}
}

int			ft_backtracking(int size, char *tab, t_tet *l)
{
	int			i;
	int			z;

	if (!l)
		return (1);
	i = 0;
	while (tab[i] && (i + l->w * l->h) < size * size)
	{
		if ((z = ft_isfree(size, tab, l, i)))
		{
			printf("test %d\n", z);
			ft_place(size, tab, l, i);
			if (ft_backtracking(size, tab, l->next))
				return (1);
			ft_reset(size, tab, l, i);
		}
		i++;
	}
	return (0);
}
