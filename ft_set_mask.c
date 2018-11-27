/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:37:05 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/27 11:54:01 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static void	maskset_1(int i, unsigned short ret[4]);
static void	maskset_2(int i, unsigned short ret[4]);
static void	maskset_3(int i, unsigned short ret[4]);
static void	maskset_4(int i, unsigned short ret[4]);

void		ft_set_mask(unsigned short mask[19][4])
{
	maskset_1(0, mask[0]);
	maskset_2(1, mask[1]);
	maskset_1(2, mask[2]);
	maskset_4(3, mask[3]);
	maskset_3(4, mask[4]);
	maskset_2(5, mask[5]);
	maskset_1(6, mask[6]);
	maskset_4(7, mask[7]);
	maskset_5(8, mask[8]);
	maskset_2(9, mask[9]);
	maskset_1(10, mask[10]);
	maskset_2(11, mask[11]);
	maskset_3(12, mask[12]);
	maskset_2(13, mask[13]);
	maskset_5(14, mask[14]);
	maskset_5(15, mask[15]);
	maskset_5(16, mask[16]);
	maskset_1(17, mask[17]);
	maskset_4(18, mask[18]);
}

static void	maskset_1(int i, unsigned short ret[4])
{
	if(i == 0)
		ret[0] = 0xE200;
	if(i == 2)
		ret[0] = 0x8E00;
	if(i == 6)
		ret[0] = 0x4E00;
	if(i == 10)
		ret[0] = 0x2E00;
	if(i == 17)
		ret[0] = 0xC600;
	ret[1] = 0x0010;
	ret[2] = 0x0001;
	ret[3] = 3;
}

static void	maskset_2(int i, unsigned short ret[4])
{
	if(i == 1)
		ret[0] = 0x44C0;
	if(i == 5)
		ret[0] = 0x4C40;
	if(i == 9)
		ret[0] = 0xC440;
	if(i == 11)
		ret[0] = 0x88C0;
	if(i == 13)
		ret[0] = 0x8C40;
	ret[1] = 0x0100;
	ret[2] = 0x0001;
	ret[3] = 2;
}

static void	maskset_3(int i, unsigned short ret[4])
{
	if(i == 4)
		ret[0] = 0xE400;
	if(i == 12)
		ret[0] = 0x6C00;
	ret[1] = 0x0200;
	ret[2] = 0x0002;
	ret[3] = 3;
}

static void	maskset_4(int i, unsigned short ret[4])
{
	if(i == 3)
		ret[0] = 0xC880;
	if(i == 7)
		ret[0] = 0x8C80;
	if(i == 18)
		ret[0] = 0x4C80;
	ret[1] = 0x0020;
	ret[2] = 0x0002;
	ret[3] = 4;
}
