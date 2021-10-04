/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/04 13:45:45 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static int	search_bigger(t_global *g, int needed, int *i)
{
}

static void	find_maillon(t_global *g, int needed)
{
}

static void	sort_chunk(t_global *g)
{
}
*/
static int	find_chunk(t_global *g, int max_per_chunk)
{
	t_info	*content;

	content = g->a->content;
	return ((content->pos / max_per_chunk) + 1);
}

static void	push_chunk_in_b(t_global *g, int nb_chunk, int size)
{
	int		i;
	int		index_chunk;
	int		max_per_chunk;
	int		imax;
	int		tmp;

	i = 0;
	index_chunk = 0;
	max_per_chunk = size / nb_chunk;
	while (++index_chunk <= nb_chunk)
	{
		imax = index_chunk * max_per_chunk;
		if (imax > size)
			imax = size - 3;
		dprintf(2, "Chunk #%02d/%02d imax = %3d\n", index_chunk, nb_chunk, imax);
		while (i < imax)
		{
			tmp = find_chunk(g, max_per_chunk);
			if (tmp == index_chunk)
			{
				dprintf(2, "PUSH in C#%d => %d/%d\n", tmp, i, imax);
				push_b(&g->a, &g->b, g);
				i++;
			}
			else
			{
				dprintf(2, "REV :/ %d\n", tmp);
				rev_rotate_a(&g->a, &g->b, g);
			}
		}
	}
}

void	big_sort(t_global *g)
{
	int	nb_chunk;
	int	size;

	nb_chunk = (int)(ft_sqrt(g->size) / 1.6);
	size = ft_lstsize(g->a);
	if (verif_sort(g))
		return ;
	push_chunk_in_b(g, nb_chunk, size);
	// sort_chunk(g);
}
