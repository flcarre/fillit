/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:13 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/29 11:24:01 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isfree(int size, char *tab, t_tet *e, int i)
{
	int n;
	int h;
	unsigned short bin;
	unsigned short newbin;
	char *tmp;

	newbin = 0;
	bin = 0;
	n = 0;
	h = e->h;
	tmp = ft_strnew(e->w);
	while (h)
	{
		while (n < e->w && tab[i + n])
		{
			tmp = ft_strnew(e->w);
			tmp[n] = tab[i + n];
			printf("tmp ==== %c\n", tmp[n]);
			if ((e->s)[n] == '.')
				tmp[n] = '.';
			n++;
		}
		ft_strtobin2(tmp, &newbin, (int)(e->w * e->h));
		printf("bin = %x\n", newbin);
		printf("newstr = %s\n", tmp);
		printf("   str = %s\n",e->s);
		if(newbin != 0)
		{
			printf("____________________________\n");
			return (0);
		}
		i += size;
		h--;
	}
	return(1);
}

static void	ft_place(int size, char *tab, t_tet *e, int i)
{
	int n;

	n = 0;
	while (n < e->w * e->h && tab[i + n] != 0)
	{
		if ((e->s)[n] == '#')
			tab[i + n] = e->c;
		size++;
		n++;
	}
}

static void	ft_reset(int size, char *tab, t_tet *e, int i)
{
	int n;

	n = 0;
	while (n < e->w * e->h && tab[i + n] != 0)
	{
		if ((e->s)[n] == '#')
			tab[i + n] = '.';
		size++;
		n++;
	}
}

int			ft_backtracking(int size, char *tab, t_tet *l)
{
	int			i;
	int			z;

	if (!l)
		return (1);
	i = 0;
	while (tab[i] && (i + l->w * l->h) <= size * size)
	{
		tab[1] = '#';
	/*	tab[1] = '#';
		tab[5] = '#';
		tab[9] = '#';
		tab[13] = '#';
		*/if ((z = ft_isfree(size, tab, l, i)))
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
