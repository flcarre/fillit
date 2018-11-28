/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:09:43 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 17:21:36 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (l)
		r = ft_solve(l, &s);
		ft_putendl("GOD");
	if (s)
		ft_print_square(&s, r);
	ft_del_tetriminos(&l);
	close(fd);
	return (r < 0 ? 1 : 0);
}
