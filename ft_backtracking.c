/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:13 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/29 12:31:29 by lutsiara         ###   ########.fr       */
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
	while (n < e->w * e->h)
	{
		tmp[n] = tab[i + n % e->w];
		if ((e->s)[n] == '.')
			tmp[n] = '.';
		n++;
		if (n % e->w == 0)
			i += size;
	}
	ft_strtobin2(tmp, &newbin, (int)(e->w * e->h));
	free(tmp);
	if(newbin == 0)
		return (1);
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
	while (i < size * size)
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
