/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:33:43 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 19:20:18 by lutsiara         ###   ########.fr       */
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
	/*
	if (!list || !(*list))
		return ;
	ft_del_tetriminos(&(*list)->next);
	ft_lstdel((t_list **)&((*list)->content), &ft_delcontent);
	(*list)->content_size = 0;
	ft_lstdelone(list, &ft_delcontent);
*/
}
