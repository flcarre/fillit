/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:09:43 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/23 19:13:22 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_list			*l;
	char			*tmp;
	char			*s;
	char			*line;
	int				fd;
	unsigned short	*y;
	unsigned short	x;
	unsigned short	mask;
	unsigned short	end;

	if (ac != 2)
	{
		ft_putendl("error");
		return (1);
	}
	fd = open(av[ac - 1], O_RDONLY);
	line = (void *)0;
	tmp = (void *)0;
	while (get_next_line(fd, &line))
	{
		s = tmp;
		tmp = ft_strjoin(tmp, line);
		if (s)
			free(s);
		free(line);
		line = (void *)0;
	}
	close(fd);
	if (!(l = ft_new_tetrimino(tmp)))
		return (1);
	x = 0x44C0;
	y = (unsigned short *)(ft_lstipos((t_list *)l->content, 1))->content;
	mask = 0x0010;
	end = 0x0001;
	while ((x & end) != end)
	{
		if ((x & *y) == *y)
		{
			printf("valid: %x\n", x & *y);
			return (0);
		}
		if ((x & mask) == mask)
		{
			x = x >> 2;
			mask = mask >> 4;
		}
		else
			x = x >> 1;
	}
	printf("invalid: %x\n", x & *y);
	return (0);
}
