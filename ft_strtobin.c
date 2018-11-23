/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:00:49 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/23 18:10:25 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_strtobin(char *tetrimino, unsigned short *bin)
{
	int				len;
	unsigned int	i;

	len = 16;
	i = 0;
	while (len--)
	{
		if (tetrimino[len] == '.')
			i++;
		else if (tetrimino[len] == '#')
			*bin += (unsigned short)ft_paw(2, i++);
	}
}
