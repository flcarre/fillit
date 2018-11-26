/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:59:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/26 21:12:26 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_badchar(char *line)
{
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (1);
		line++;
	}
	return (0);
}

static void	ft_del_tetriminos(t_list **list)
{
	if (!list || !(*list))
		return ;
	ft_del_tetriminos(&(*list)->next);
	ft_lstdel((t_list **)&((*list)->content), &ft_delcontent);
	(*list)->content_size = 0;
	ft_lstdelone(list, &ft_delcontent);
}

static int	ft_get(const int fd, char **tmp)
{
	char		*line;
	char		*s;
	int			i;
	int			r;

	i = 0;
	*tmp = (void *)0;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		if (i > 4 || ft_strlen(line) != 4 || ft_badchar(line))
		{
			free(line);
			ft_memdel((void **)&(*tmp));
			return (-1);
		}
		if (!ft_strlen(line))
			return (1);
		s = *tmp;
		*tmp = ft_strjoin(*tmp, line);
		if (s)
			free(s);
		i++;
	}
	ft_memdel((void **)&line);
	return ((r < 0) ? -1 : 0);
}

int			ft_get_tetriminos(const int fd, t_list **list)
{
	t_list		*new;
	char		*tmp;
	int			r;

	while ((r = ft_get(fd, &tmp)) > 0)
	{
		ft_lstenqueue(list, (new = ft_new_tetrimino(tmp)));
		if (!new)
		{
			ft_del_tetriminos(list);
			return (-1);
		}
	}
	if (r < 0)
	{
		ft_memdel((void **)&tmp);
		ft_del_tetriminos(list);
		return (1);
	}
	return (0);
}
