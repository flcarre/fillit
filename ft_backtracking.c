/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:13 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/27 13:39:39 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int ft_isfree(int size, char *tab, t_list *l, int *i)
{
	unsigned short w;
	unsigned short h;
	int n;

	n = -1;
	w = *((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content);
	h = *((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content);
	while(++n < )
}

int ft_backtracking(int size, char *tab, t_list *l)
{

}
