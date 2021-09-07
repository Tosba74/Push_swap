/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/08/25 15:46:27 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_list(t_global *g, int size, int sep)
{
	int	i;

	i = 0;
	while (i < ((size - sep)))
	{
		rev_rotate_a(&g->a, &g->b, g);
		push_b(&g->a, &g->b, g);
		i++;
	}
}

void	recurs_loop(t_global *g, int size)
{
	int	sep;

	sep = size / 2;
	if (size == 1 || size == 0)
		return ;
	split_list(g, size, sep);
	recurs_loop(g, sep);
	push_a(&g->a, &g->b, g);
	sort_two(g, 1);
}

void	others_sort(t_global *g)
{
	recurs_loop(g, g->size);
}
