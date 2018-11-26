/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:37:05 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/26 23:00:11 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short **ft_set_mask()
{
	unsigned short **mask[19][3];
	mask[0] = maskset0(0);
	mask[1] = maskset1(1);
	mask[2] = maskset0(2);
	mask[3] = maskset3(3);
	mask[4] = maskset2(4);
	mask[5] = maskset1(5);
	mask[6] = maskset0(6);
	mask[7] = maskset3(7);
	mask[8] = maskset4(8);
	mask[9] = maskset1(9);
	mask[10] = maskset0(10);
	mask[11] = maskset1(11);
	mask[12] = maskset2(12);
	mask[13] = maskset1(13);
	mask[14] = maskset4(14);
	mask[15] = maskset4(15);
	mask[16] = maskset4(16);
	mask[17] = maskset0(17);
	mask[18] = maskset3(18);
	ret(mask);
}

/* x = ret[1] end = ret[2]*/

static unsigned short *masksetO(int i)
{
	unsigned short *ret;
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
}

static unsigned short *maskset1(int i)
{
	unsigned short *ret;
	if(i == 1)
		ret[0] = 0x44C0;
	if(i == 5)
		ret[0] = 0x4C40;
	if(i == 9)
		ret[] = 0xC440;
	if(i == 11)
		ret[0] = 0x88C0;
	if(i == 13)
		ret[0] = 0x8C40;
	ret[1] = 0x0100;
	ret[2] = 0x0001;
}

static unsigned short *maskset2(int i)
{
	unsigned short *ret;
	if(i == 4)
		ret[0] = 0xE400;
	if(i == 12)
		ret[0] = 0x6C00;
	ret[1] = 0x0200;
	ret[2] = 0x0002;
}

static unsigned short *maskset3(int i)
{
	unsigned short *ret;
	if(i == 3)
		ret[0] = 0xC880;
	if(i == 7)
		ret[0] = 0x8C80;
	if(i == 18)
		ret[0] = 0x4C80;
	ret[1] = 0x0020;
	ret[2] = 0x0002;
}
