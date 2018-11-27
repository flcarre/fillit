/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarre <flcarre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:28:35 by flcarre           #+#    #+#             */
/*   Updated: 2018/11/27 17:32:18 by flcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_print_square(char **s, int size)
{
	int i;

	i = 0;
	while ((*s)[i])
	{
		if (i != 0 && !(i % size))
			ft_putchar('\n');
		ft_putchar((*s)[i]);
		i++;
	}
	ft_putchar('\n');
	free(*s);
}
