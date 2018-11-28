/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binchar_to_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:56:41 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/28 23:47:21 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_paaw(long x, unsigned int n)
{
	long	r;

	if (!n)
		return (1);
	r = 1;
	while (n--)
		r = r * x;
	return (r);
}

void	ft_strtobin2(char *tetrimino, unsigned short *bin, int len)
{
	unsigned int	i;

	i = 0;
	while (len--)
	{
		if (tetrimino[len] == '.')
			i++;
		else if (tetrimino[len] == '#')
			*bin += (unsigned short)ft_paaw(2, i++);
	}
}
