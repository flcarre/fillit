/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mask2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:40:47 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/28 20:40:24 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	maskset_6(int i, unsigned short ret[4])
{
	if (i == 15)
	{
		ret[0] = 0x8888;
		ret[1] = 0x0001;
		ret[2] = 0x0001;
		ret[3] = 1;
	}
	if (i == 16)
	{
		ret[0] = 0xCC00;
		ret[1] = 0x0100;
		ret[2] = 0x0001;
		ret[3] = 2;
	}
}

void		maskset_5(int i, unsigned short ret[4])
{
	if (i == 8)
	{
		ret[0] = 0xE800;
		ret[1] = 0x0400;
		ret[2] = 0x0004;
		ret[3] = 4;
	}
	if (i == 14)
	{
		ret[0] = 0xF000;
		ret[1] = 0x1000;
		ret[2] = 0x0001;
		ret[3] = 4;
	}
	maskset_6(i, ret);
}
