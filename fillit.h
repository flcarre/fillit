/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:15:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/27 17:20:43 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

void				ft_del_tetriminos(t_list **list);
t_list				*ft_new_tetrimino(char *tetrimino);
int					ft_get_tetriminos(const int fd, t_list **list);
void				ft_set_mask(unsigned short mask[19][4]);
void				maskset_5(int i, unsigned short ret[4]);
int					ft_isinvalid(t_list **list);
void				ft_strtobin(char *tetrimino, unsigned short *bin);
void				ft_measure_tetrimino(unsigned short *bin, \
					unsigned short *width, unsigned short *height);
int					ft_solve(t_list *l, char **tab);
int					ft_backtracking(int size, char *tab, t_list *l);
void				ft_print_square(char **s, int size);

#endif
