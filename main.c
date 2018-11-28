/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:09:43 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 17:50:41 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_max(t_list *l)
{
	int		max;
	unsigned short h;
	unsigned short w;

	max = 0;
	ft_putendl("1");
	while (l)
	{
		ft_putendl("1.1");
		h = *((unsigned short *)(ft_lstipos((t_list *)l->content, 4))->content);
		ft_putendl("1.2");
		w = *((unsigned short *)(ft_lstipos((t_list *)l->content, 3))->content);
		ft_putendl("2");
		max = ((unsigned short)max < w) ? (int)w : max;
		ft_putendl("3");
		max = ((unsigned short)max < h) ? (int)h : max;
		ft_putendl("4");
		l = l->next;
		ft_putendl("5");
	}
	ft_putendl("WTF");
	return (max);
}

int		main(int ac, char **av)
{
	t_list			*l;
	t_list			*i;
	int				fd;
	int				r;
	char			*s;

	l = (void *)0;
	s = (void *)0;
	fd = open(av[ac - 1], O_RDONLY);
	if (ac != 2 || (r = ft_get_tetriminos(fd, &l)) == 1 || ft_isinvalid(&l))
	{
		ft_putendl("error");
		return (1);
	}
	i = l;
	while(i)
	{
		ft_putendl("width");
		ft_putnbr(*((unsigned short *)(ft_lstipos((t_list *)i->content, 3))->content));
		ft_putchar('\n');
		ft_putendl("height");
		ft_putnbr(*((unsigned short *)(ft_lstipos((t_list *)i->content, 4))->content));
		ft_putchar('\n');
		ft_putendl("bin");
		ft_putnbr(*((unsigned short *)(ft_lstipos((t_list *)i->content, 1))->content));
		ft_putchar('\n');
		ft_putendl("str");
		ft_putendl((char *)(ft_lstipos((t_list *)i->content, 0))->content);
		ft_putendl("letter");
		ft_putchar(*((char *)(ft_lstipos((t_list *)i->content, 2))->content));
		ft_putchar('\n');
		ft_putchar('\n');
		i = i->next;
	}
	r = ft_fit_tetriminos(l);
	if (!r && l)
		r = ft_solve(l, &s, ft_max(l));
		ft_putendl("GOD");
	if (s)
		ft_print_square(&s, r);
	ft_del_tetriminos(&l);
	close(fd);
	return (r < 0 ? 1 : 0);
}
