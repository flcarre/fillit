/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:13 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/28 14:05:24 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isfree(int size, char *tab, t_list *l, int i)
{
	unsigned short	w;
	unsigned short	h;
	char			*t;
	unsigned short	n[3];

	n[2] = 1;
	n[0] = 0;
	t = (char *)(ft_lstipos((t_list *)l->content, 0))->content;
	w = *((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content);
	h = *((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content);
	if (tab[i] == '.' || (n[2] = 0))
	{
		n[1] = 0;
		while (n[1] < w * h)
		{
			n[0] += (!(n[1] % w) && n[1]) ? size : 0;
			n[2] = (tab[i + n[0]] == '.' && t[n[1]] == '#') ? 1 : n[2];
			n[2] = (tab[i + n[0]] != '.' && t[n[1]] == '#') ? 0 : n[2];
			if (!n[2])
				return (0);
			n[1]++;
		}
	}
	return ((int)n[2]);
}

static void	ft_place(int size, char *tab, t_list *l, int i)
{
	unsigned short	w;
	unsigned short	h;
	char			*t;
	unsigned short	n[2];
	char			c;

	t = (char *)(ft_lstipos((t_list *)l->content, 0))->content;
	c = *((char *)(ft_lstipos((t_list *)l->content, 2))->content);
	w = *((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content);
	h = *((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content);
	n[1] = 0;
	n[0] = 0;
	while (n[1] < w * h)
	{
		n[0] += (!(n[1] % w) && n[1]) ? size : 0;
		tab[i + n[0]] = (tab[i + n[0]] == '.' && t[n[1]] == '#') ? c : '.';
		n[1]++;
	}
}

static void	ft_reset(int size, char *tab, t_list *l, int i)
{
	unsigned short	w;
	unsigned short	h;
	char			*t;
	unsigned short	n[2];

	t = (char *)(ft_lstipos((t_list *)l->content, 0))->content;
	w = *((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content);
	h = *((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content);
	n[1] = 0;
	n[0] = 0;
	while (n[1] < w * h)
	{
		n[0] += (!(n[1] % w) && n[1]) ? size : 0;
		tab[i + n[0]] = (t[n[1]] == '#') ? '.' : tab[i + n[0]];
		n[1]++;
	}
}

int			ft_backtracking(int size, char *tab, t_list *l)
{
	int			i;

	if (!l)
		return (1);
	i = 0;
	while (tab[i])
	{
		if (ft_isfree(size, tab, (t_list *)l->content, i))
		{
			ft_place(size, tab, (t_list *)l->content, i);
			if (ft_backtracking(size, tab, l->next))
				return (1);
			ft_reset(size, tab, (t_list *)l->content, i);
		}
		i++;
	}
	return (0);
}
