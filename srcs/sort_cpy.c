/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 19:53:39 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	complet_chunks(t_global *g ,int nb_chunk)
{
	int		i;
	int		chunk;
	int		chunk_max;

	i = 0;
	chunk = 1;
	chunk_max = (g->size) / nb_chunk;
	while (chunk <= nb_chunk)
	{	
		while (i <= (chunk_max * chunk) && g->a)
		{
			if (!content_cmp(&g->a, chunk_max * chunk))
			{
				sort_two(g, 1);
				push_a(&g->a, &g->b, g);
				sort_two(g, -1);
				i++;
				dprintf(2, "AAAAaaaahhh\n");
			}
			else
				rotate_a(&g->a, &g->b, g);
		}
		chunk++;
	}
	push_a(&g->a, &g->b, g);
}

static void	sort_chunk(t_global *g, int nb_chunk)
{
	int	i;
	int	chunk_max;

	i = g->size;
	chunk_max = (g->size) / nb_chunk;
	dprintf(2, "OOOOoooohhh\n");
	while (nb_chunk >= 0)
	{
		nb_chunk--;
		while (i >= (chunk_max * nb_chunk) && i >= 0)
		{
			if (!content_cmp(&g->b, i))
			{
				sort_two(g, -1);
				push_b(&g->a, &g->b, g);
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
	sort_chunk(g, nb_chunk);
	print_list(g);
}

// void	sort_cent(t_global *g, int neg)
// {
// 	complet_chunks(g);
// 	print_list(g);
// 	sort_chunk(g);
// 	print_list(g);
// 	(void) neg;
// }
