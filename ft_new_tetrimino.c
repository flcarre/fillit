/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tetrimino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:06:28 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/03 18:27:04 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet		*ft_new_tetrimino(char *tetrimino)
{
	t_tet			*new;
	static int		i = 0;

	if (!(new = (t_tet *)malloc(sizeof(t_tet))))
		return ((void *)0);
	new->s = ft_strdup(tetrimino);
	new->b = 0;
	ft_strtobin(tetrimino, &(new->b));
	new->c = 'A' + i++;
	ft_measure_tetrimino(&(new->b), &(new->w), &(new->h));
	new->next = (void *)0;
	ft_memdel((void **)&tetrimino);
	return (new);
}
