/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:15:09 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/22 22:27:08 by flcarre          ###   ########.fr       */
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

#endif
