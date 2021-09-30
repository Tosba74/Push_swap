/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/18 13:33:21by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_small(t_global *g, int *i)
{
	int		ret;
	int		tmp;
	t_list	*cpy;

	ret = 0;
	cpy = g->b;
	tmp = g->size;
	while (g->b)
	{
		if (content_cmp(&g->b, tmp) < 0 && get_position(&g->b) != -1)
		{
			ret = *i;
			tmp = get_position(&g->b);
		}
		g->b = g->b->next;
		(*i)++;
	}
	g->b = cpy;
	return (ret);
}

static void	push_smaller(t_global *g)
{
	int	i;
	int	pos;

	i = 0;
	pos = search_small(g, &i);
	// dprintf(2, "pos = %d || i = %d\n", pos, i);
	if (i == 0)
		return ;
	if (pos <= i / 2)
	{
		while (pos-- != 0)
			rotate_b(&g->a, &g->b, g);
		push_a(&g->a, &g->b, g);
	}
	else if (pos > i / 2)
	{
		i -= pos;
		while (i-- != 0)
			rev_rotate_b(&g->a, &g->b, g);
		push_a(&g->a, &g->b, g);
	}
}

void	rebuild_chunk(t_global *g, int mpc, int chunk, int *i)
{
	(void)mpc;
	(void)chunk;
	while (*i != 2)
	{
		push_smaller(g);
		--(*i);
	}
	// print_list(g);
	push_a(&g->a, &g->b, g);
}

void	sort_chunk(t_global *g, int nb_chunk)
{
	int	i;
	int	max_per_chunk;

	// i = g->size - 1;
	i = get_position(&g->a) - 1;
	max_per_chunk = (g->size) / nb_chunk;
	while (nb_chunk-- > 0)
	{	
		// dprintf(2, "Chunk#%d => Max=%d | i => %d\n", nb_chunk, max_per_chunk, i);
		rebuild_chunk(g, max_per_chunk, nb_chunk, &i);
		print_list(g);
	}
}

static void	complet_chunks(t_global *g, int nb_chunk)
{
	int		i;
	int		index_chunk;
	int		max_per_chunk;

	i = 0;
	index_chunk = 0;
	max_per_chunk = g->size / nb_chunk;
	while (index_chunk++ < nb_chunk)
	{
		while ((i < (index_chunk * max_per_chunk) && i < g->size)
			|| !a_is_sort(g->a))
		{
			dprintf(2, "%d < %d\n", i, (index_chunk * max_per_chunk));
			if (content_cmp(&g->a, (index_chunk * max_per_chunk)) < 0)
			{
				push_b(&g->a, &g->b, g);
				i++;
			}
			else
			{
				rotate_a(&g->a, &g->b, g);
			}
		}
	}
	choose_sort(g, g->size - i);
}

void	big_sort(t_global *g)
{
	int	nb_chunk;

	nb_chunk = (int)(ft_sqrt(g->size) / 1.6);
	// dprintf(2, "size => %d | nb => %d\n", g->size, nb_chunk);
	complet_chunks(g, nb_chunk);
	print_list(g);
	sort_chunk(g, nb_chunk);
	print_list(g);
}
