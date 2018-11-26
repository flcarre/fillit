/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:59:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/26 19:50:31 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_badchar(char *line)
{
	while (*line)
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

	i = 0;
	*tmp = (void *)0;
	while (get_next_line(fd, &line))
	{
		if (i > 3 || ft_strlen(line) > 4 || ft_badchar(line))
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
	return (0);
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

	return (0);
}
