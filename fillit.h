/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:15:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/28 18:05:55 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct		s_tet
{
	char *s;
	unsigned short b;
	char c;
	unsigned short w;
	unsigned short h;
	struct s_tet	*next;
}					t_tet;

void				ft_del_tetriminos(t_tet **list);
t_tet				*ft_new_tetrimino(char *tetrimino);
int					ft_get_tetriminos(const int fd, t_tet **list);
void				ft_set_mask(unsigned short mask[19][4]);
void				maskset_5(int i, unsigned short ret[4]);
int					ft_isinvalid(t_tet **list);
void				ft_strtobin(char *tetrimino, unsigned short *bin);
void				ft_measure_tetrimino(unsigned short *bin, \
					unsigned short *width, unsigned short *height);
int					ft_solve(t_tet *l, char **tab);
int					ft_fit_tetriminos(t_tet *list);
int					ft_backtracking(int size, char *tab, t_tet *l);
void				ft_print_square(char **s, int size);

#endif
