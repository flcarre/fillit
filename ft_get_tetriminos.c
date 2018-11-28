/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:59:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 16:26:01 by lutsiara         ###   ########.fr       */
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

static int	ft_get(const int fd, char **tmp)
{
	char		*line;
	char		*s;
	int			r[2];

	r[1] = 0;
	tmp = (void *)0;
	while ((r[0] = get_next_line(fd, &line)) > 0 && ft_strlen(line))
	{
		if (r[1]++ > 4 || ft_strlen(line) != 4 || ft_badchar(line))
		{
			free(line);
			ft_memdel((void **)&(*tmp));
			return (-1);
		}
		s = *tmp;
		*tmp = ft_strjoin(*tmp, line);
		if (s)
			free(s);
	}
	if ((!ft_strlen(line) && r[1] == 4))
	{	
		ft_memdel((void **)&line);
		return (1);
	}
	return ((r[0] < 0) ? -2 : 0);
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
		return (r == -2 ? -1 : 1);
	}
	return (0);
}
