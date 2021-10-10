/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/11 00:22:46 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_it(t_global *g, int imax, int *i, int *j)
{
	if (((t_info *)(g->a->content))->pos < imax)
	{
		push_b(g);
		(*i)++;
		return (1);
	}
	else if (((t_info *)(g->a->content))->pos > (g->size - imax))
	{
		push_b(g);
		rotate_b(g);
		(*j)--;
		return (1);
	}
	return (0);
}

static void	create_chunk(t_global *g, int nb_chunk)
{
	int		i;
	int		j;
	int		index_chunk;
	int		max_per_chunk;
	int		imax;

	i = 0;
	j = g->size;
	index_chunk = 0;
	max_per_chunk = g->size / nb_chunk;
	while (++index_chunk != g->size)
	{
		imax = max_per_chunk * index_chunk;
		while (i < imax && i < g->size && j > (g->size - imax) && j != 0
			&& g->a)
			if (!push_it(g, imax, &i, &j))
				rotate_a(g);
	}
}

void	big_sort(t_global *g)
{
	int	nb_chunk;

	nb_chunk = (int)(ft_sqrt(g->size) / 1.5);
	create_chunk(g, nb_chunk);
	while (g->b)
		push_bigger(g);
}
