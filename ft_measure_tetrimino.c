/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_measure_tetrimino.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:01:57 by lutsiara          #+#    #+#             */
/*   Updated: 2018/11/26 18:53:24 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	ft_max(unsigned short *i, unsigned short *j)
{
	unsigned short min_i;
	unsigned short max_j;
	unsigned short n;

	min_i = 4;
	max_j = 0;
	n = 0;
	while (n < 4)
	{
		if (i[n] < min_i)
			min_i = i[n];
		n++;
	}
	n = 0;
	while (n < 4)
	{
		if (j[n] > max_j)
			max_j = j[n];
		n++;
	}
	ft_putnbr(max_j - min_i);
	return (max_j - min_i);
}

static unsigned short	ft_height(unsigned short *bin)
{
	unsigned short i;
	unsigned short size;
	unsigned short beg;
	unsigned short end;

	beg = 0x8000;
	end = 0x0001;
	i = 0;
	size = 4;
	while ((*bin & beg) != beg)
	{
		beg = beg >> 1;
		i++;
		size = (!(i % 4)) ? size - 1 : size;
	}
	i = 0;
	while ((*bin & end) != end)
	{
		end = end << 1;
		i++;
		size = (!(i % 4)) ? size - 1 : size;
	}
	return (size);
}

static unsigned short	ft_width(unsigned short *bin)
{
	unsigned short i[4];
	unsigned short j[4];
	unsigned short beg[4];
	unsigned short end[4];
	unsigned short a;

	a = 0;
	while (a < 4)
	{
		beg[a] = 0x8000 >> (4 * a);
		end[a] = 0x0001 << (4 * a);
		i[a] = 0;
		i[a]--;
		while (++i[a] < 4 && (*bin & beg[a]) != beg[a])
			beg[a] = beg[a] >> 1;
		j[a] = 4;
		j[a]++;
		while (--j[a] > 0 && (*bin & end[a]) != end[a])
			end[a] = end[a] << 1;
		a++;
	}
	return (ft_max(i, j));
}

void					ft_measure_tetrimino(unsigned short *bin, \
						unsigned short *width, unsigned short *height)
{
	*width = ft_width(bin);
	*height = ft_height(bin);
}
