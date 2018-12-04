/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:33:43 by lutsiara          #+#    #+#             */
/*   Updated: 2018/12/03 18:20:58 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_del_tetriminos(t_tet **list)
{
	if (!list || !(*list))
		return ;
	ft_del_tetriminos(&(*list)->next);
	free((*list)->s);
	free((*list));
}
