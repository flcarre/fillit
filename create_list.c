/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:52:37 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/22 22:32:38 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char *ft_strconv(char *str)
{
	unsigned long i;

	i = 0;
	while(str[i] != 0)
	{
		if (str[i] == '#')
			str[i] = '1';
		else if (str[i] == '.')
			str[i] = '0';
		else
			return(NULL);
		i++;
	}
	return(str);
}

long ft_paw(long x, unsigned int n)
{
	long res;

	if (n == 0)
		return (1);
	if (n < 0)
		return (0);
	res = x;
	if (n > 1)
		res = x * ft_paw(x, n - 1);
	return (res);
}

unsigned short binchar_to_short(char *str)
{
	unsigned int i;
	unsigned int n;
	unsigned short ret;
	int tmp;

	i = 0;
	n = 15;
	ret = 0;
	while(i < 16)
	{
		tmp = ret;
		ret += (str[i] - '0') * ft_paw(2, n);
		i++;
		n--;
	}
}

t_tetri		*create_list(char *str)
{
	t_tetri		*new;
	static i = 0;

	if (!(new = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
		return ((void *)0);
	if (ft_strlen(str) != 16)
		return ((void *)0);
	new->str_bin = ft_strconv(str);
	new->bin = binchar_to_short(str);
	new->letter = i + 'A';
	free(new);
}
