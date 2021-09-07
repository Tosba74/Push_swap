/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 22:17:20 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	complet_chunks(t_global *g ,int nb_chunk)
{
	int		i;
	int		index_chunk;
	int		max_per_chunk;

	i = 0;
	index_chunk = 1;
	max_per_chunk = (g->size) / nb_chunk;
	while (index_chunk <= nb_chunk)
	{	
		while (i++ <= (max_per_chunk * index_chunk) && g->a)
		{
			if (content_cmp(&g->a, max_per_chunk * index_chunk) < 0)
			{
				if (g->a->next && where_am_i(&g->a, 1) > 0)
					swap_a(&g->a, &g->b, g);
				else
					push_b(&g->a, &g->b, g);
				// sort_two(g, -1);
				index_chunk++;
				dprintf(2, "AAAAaaaahhh\n");
			}
			else
				rotate_a(&g->a, &g->b, g);
		}
	}
	push_b(&g->a, &g->b, g);
}

void	sort_chunk(t_global *g, int nb_chunk)
{
	int	i;
	int	max_per_chunk;

	i = g->size;
	max_per_chunk = (g->size) / nb_chunk;
	dprintf(2, "OOOOoooohhh\n");
	while (nb_chunk >= 0)
	{
		nb_chunk--;
		while (i >= (max_per_chunk * nb_chunk) && i >= 0)
		{
			if (!content_cmp(&g->b, i))
			{
				// sort_two(g, -1);
				push_a(&g->a, &g->b, g);
				i++;
			}
			else
				rotate_b(&g->a, &g->b, g);
		}
	}
}

void	big_sort(t_global *g)
{
	int	nb_chunk;

	nb_chunk = (int)(ft_sqrt(g->size) / 1.6);
	complet_chunks(g, nb_chunk);
	print_list(g);
	// sort_chunk(g, nb_chunk);
	// print_list(g);
}
