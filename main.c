/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:09:43 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 20:41:48 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tet			*l;
	t_tet			*i;
	int				fd;
	int				r;
	int				z;
	char			*s;

	l = (void *)0;
	s = (void *)0;
	r = 0;
	z = 0;
	fd = open(av[ac - 1], O_RDONLY);
	if (ac != 2 || (r = ft_get_tetriminos(fd, &l)) == 1 || (z = ft_isinvalid(&l)))
	{
		printf("%d\n", z);
		ft_putendl("error");
		return (1);
	}
	i = l;
	while(i)
	{
		ft_putendl("width");
		ft_putnbr(i->w);
		ft_putchar('\n');
		ft_putendl("height");
		ft_putnbr(i->h);
		ft_putchar('\n');
		ft_putendl("bin");
		ft_putnbr(i->b);
		ft_putchar('\n');
		ft_putendl("str");
		ft_putendl(i->s);
		ft_putendl("letter");
		ft_putchar(i->c);
		ft_putchar('\n');
		ft_putchar('\n');
		i = i->next;
	}
	if (l)
		r = ft_solve(l, &s);
	if (s)
		ft_print_square(&s, r);
	ft_del_tetriminos(&l);
	close(fd);
	return (r < 0 ? 1 : 0);
}
