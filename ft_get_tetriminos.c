/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:59:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 20:30:08 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static void	ft_delbuff(char **s)
{
	if (*s)
		free(*s);
	if (*(s + 1))
		free(*(s + 1));
}

static int	ft_get(const int fd, char **tmp)
{
	char		*l[2];
	int			r[2];

	r[1] = 0;
	*tmp = (void *)0;
	while ((r[0] = get_next_line(fd, &l[0])) > 0 && ft_strlen(l[0]) && ++r[1])
	{
		if (r[1] > 4 || ft_strlen(l[0]) != 4 || ft_badchar(l[0]))
		{
			ft_memdel((void **)&l[0]);
			return (-1);
		}
		l[1] = *tmp;
		*tmp = ft_strjoin(*tmp, l[0]);
		ft_delbuff(l);
	}
	if (!ft_strlen(l[0]))
	{
		ft_memdel((void **)&l[0]);
		return ((r[1] != 4) ? -1 : 1);
	}
	return ((r[0] < 0) ? -2 : 0);
}

static void	ft_push_back(t_tet **list, t_tet *new)
{
	if (!(*list))
	{
		*list = new;
		return ;
	}
	ft_push_back(&(*list)->next, new);
}

int			ft_get_tetriminos(const int fd, t_tet **list)
{
	t_tet		*new;
	char		*tmp;
	int			r[2];

	r[1] = 0;
	while ((r[0] = ft_get(fd, &tmp)) > 0)
	{
		ft_push_back(list, (new = ft_new_tetrimino(tmp)));
		if (!new)
		{
			ft_memdel((void **)&tmp);
			ft_del_tetriminos(list);
			return (-1);
		}
		r[1]++;
	}
	if (r[1] > 26 || r[0] < 0)
	{
		ft_del_tetriminos(list);
		ft_memdel((void **)&tmp);
		return (r[0] == -2 ? -1 : 1);
	}
	return (0);
}
