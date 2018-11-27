/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:09:43 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/27 12:20:02 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_list			*l;
	t_list			*i;
	int				fd;
	int				r;
	int				n;
	unsigned short	*y;
	unsigned short	x;
	unsigned short	end;
	unsigned short	depl;
	unsigned short	mask;
	unsigned short	set_mask[19][4];

	if (ac != 2)
	{
		ft_putendl("error");
		return (1);
	}
	fd = open(av[ac - 1], O_RDONLY);
	if ((r = ft_get_tetriminos(fd, &l)) == 1)
	{
		ft_putendl("error");
		return (1);
	}
	else if (r == -1)
		return (1);
	close(fd);
	i = l;
	while(i)
	{
		ft_putendl("width");
		ft_putnbr(*((int *)(ft_lstipos((t_list *)i->content, 3))->content));
		ft_putchar('\n');
		ft_putendl("height");
		ft_putnbr(*((int *)(ft_lstipos((t_list *)i->content, 4))->content));
		ft_putchar('\n');
		ft_putendl("bin");
		ft_putnbr(*((int *)(ft_lstipos((t_list *)i->content, 1))->content));
		ft_putchar('\n');
		ft_putendl("str");
		ft_putendl((char *)(ft_lstipos((t_list *)i->content, 0))->content);
		ft_putendl("letter");
		ft_putchar(*((char *)(ft_lstipos((t_list *)i->content, 2))->content));
		ft_putchar('\n');
		ft_putchar('\n');
		i = i->next;
	}
	i = l;
	ft_set_mask(set_mask);
	while (i)
	{
		y = (unsigned short *)(ft_lstipos((t_list *)i->content, 1))->content;
		n = 0;
		while (n < 19)
		{
			mask = set_mask[n][1];
			x = set_mask[n][0];
			end = set_mask[n][2];
			depl = set_mask[n][3];
			while ((x & end) != end)
			{
				if ((x & *y) == *y)
				{
					printf("valid: %x\n", x & *y);
					break ;
				}
				if ((x & mask) == mask)
				{
					x = x >> depl;
					mask = mask >> 4;
				}
				else
					x = x >> 1;
			}
			if ((x & *y) == *y)
			{
				printf("valid: %x\n", x & *y);
				break ;
			}
			n++;
		}
		if (n == 19)
			printf("invalid: %x\n", x & *y);
		i = i->next;
	}
	return (0);
}
