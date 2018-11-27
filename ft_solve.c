/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:58:23 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/27 13:28:27 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void ft_square(char **tab, int size)
{
	*tab = ft_strnew(size * size + 1);
	ft_memset((void *)*tab, (int)'.', (unsigned long)(size * size));
}

static int ft_max(t_list *l)
{
	int max;

	max = 0;
	while(l)
	{
		max = ((unsigned short)max < \
		*((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content)) ? \
		(int)*((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content) : \
		max;
		max = ((unsigned short)max < \
		*((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content)) ? \
		(int)*((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content) : \
		max;
		l = l->next;
	}
	return (max);
}

char *ft_solve(t_list *l)
{
	int size;
	char *tab;
	size = ft_max(l);
	while (!ft_backtracking(size, tab, l))
	{
		ft_square(&tab, size);
		free(tab);
		tab = (void *)0;
		size++;
	}
	return (tab);
}
