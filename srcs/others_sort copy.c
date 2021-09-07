/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_sort copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/08/25 20:21:10 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**split_shit(int *array, int size, int sep)
{
	int	i;
	int	y;
	int	*ret[2];

	i = -1;
	y = 0;
	ret[0] = (int *)wrmalloc(sizeof(int) * sep);
	ret[1] = (int *)wrmalloc(sizeof(int) * (size - sep));
	while (++i < size)
	{
		if (i < sep)
			ret[0][i] = array[i];
		else
			ret[1][y++] = array[i];
	}
	return (ret);
}

void	recurs_loop(int *array, int size)
{
	int	sep;
	int	*new[2];

	sep = size / 2;
	if (size == 1)
	{
		ft_putstr("----------\n");
		ft_putnbr(array[0]);
		ft_putstr("----------\n");
		return ;
	}
	new = split_shit(array, size, sep);
	print_array(new[0], sep);
	print_array(new[1], size - sep);
	recurs_loop(new[0], sep);
	recurs_loop(new[1], size - sep);
	return (merge_sort());
}

void	others_sort(t_global *g)
{
	recurs_loop(g->array, g->size);
}
