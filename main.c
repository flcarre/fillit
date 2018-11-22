/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:09:43 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/22 17:14:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char			*line;
	int				fd;
	unsigned short	x;
	unsigned short	y;
	unsigned short	mask;
	unsigned short	end;

	if (ac != 2)
	{
		ft_putendl("error");
		return (1);
	}
	fd = open(av[ac - 1], O_RDONLY);
	line = (void *)0;
	get_next_line(fd, &line);
	ft_putendl(line);
	ft_strdel(&line);
	close(fd);
	x = 0x44C0;
	y = 0x0226;
	mask = 0x0010;
	end = 0x0001;
	while ((x & end) != end)
	{
		printf("%x\n", x);
		//if ((y & x) == x)
		//	break;
		if ((x & mask) == mask)
		{
			x = x >> 2;
			mask = mask >> 4;
		}
		else
			x = x >> 1;
	}
	printf("%x\n", x);
	//printf("%x\n", x & y);
	return (0);
}
