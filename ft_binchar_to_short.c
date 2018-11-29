/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binchar_to_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:56:41 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/29 10:34:48 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_strtobin2(char *tetrimino, unsigned short *bin, int len)
{
	unsigned int	i;

	i = 0;
	while (len--)
	{
		if (tetrimino[len] == '.')
			i++;
		else if (tetrimino[len] != '.')
			*bin += (unsigned short)ft_paw(2, i++);
	}
}
