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
	int				fd;
	int				r;
	char			*s;

	l = (void *)0;
	s = (void *)0;
	r = 0;
	fd = open(av[ac - 1], O_RDONLY);
	if (ac != 2 || (r = ft_get_tetriminos(fd, &l)) == 1 || ft_isinvalid(&l))
	{
		ft_putendl("error");
		return (1);
	}
	if (l)
		r = ft_solve(l, &s);
	if (s)
		ft_print_square(&s, r);
	ft_del_tetriminos(&l);
	close(fd);
	return (r < 0 ? 1 : 0);
}
