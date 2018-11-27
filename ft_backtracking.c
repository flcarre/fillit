/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:13 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/27 16:58:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isfree(int size, char *tab, t_list *l, int i)
{
	unsigned short	w;
	unsigned short	h;
	char			*t;
	unsigned short	n;
	unsigned short	f;

	f = 1;
	t = (char *)(ft_lstipos((t_list *)l->content, 0))->content;
	w = *((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content);
	h = *((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content);
	n = 0;
	while (n < 16)
	{
		if (tab[i])
	}
	return (0);
}

static void	ft_place(int size, char *tab, t_list *l, int i)
{

}

static void	ft_reset(int size, char *tab, t_list *l, int i)
{

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
