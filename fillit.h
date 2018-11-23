/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:15:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/23 17:45:19 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_tetri
{
	char			*str_bin;
	unsigned short	bin;
	unsigned short	height;
	unsigned short	width;
	char            letter;
	struct s_tetri	*next;
}					t_tetri;

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

t_list				*ft_new_tetrimino(char *tetrimino);
void				ft_strtobin(char *tetrimino, unsigned short *bin);
void				ft_measure_tetrimino(unsigned short *bin, \
					unsigned short *width, unsigned short *height);

#endif
