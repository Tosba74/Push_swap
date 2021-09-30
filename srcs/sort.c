/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/28 15:37:53 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_small(t_global *g, int needed, int *i)
{
	int		ret;
	t_list	*cpy;

	ret = 0;
	cpy = g->b;
	while (cpy)
	{
		if (get_position(&cpy) == needed)
			ret = *i;
		cpy = cpy->next;
		(*i)++;
	}
	return (ret);
}

static void	find_maillon(t_global *g, int needed)
{
	int		size;
	int		pos;

	size = 0;
	pos = search_small(g, needed, &size);
	if (pos <= size / 2)
		while (pos-- != 0)
			rotate_b(&g->a, &g->b, g);
	else if (pos > size / 2)
	{
		size -= pos;
		while (size-- != 0)
			rev_rotate_b(&g->a, &g->b, g);
	}
}

static void	sort_chunk(t_global *g)
{
	int	i;

	i = get_position(&g->a);
	while (--i != 0)
	{
		find_maillon(g, i);
		if (get_position(&g->b) == i)
			push_a(&g->a, &g->b, g);
	}
	push_a(&g->a, &g->b, g);
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
		while ((i < (index_chunk * max_per_chunk) && i < g->size - 3)
			|| !a_is_sort(g->a))
		{
			if (content_cmp(&g->a, (index_chunk * max_per_chunk)) < 0)
			{
				push_b(&g->a, &g->b, g);
				i++;
			}
			else
				rotate_a(&g->a, &g->b, g);
		}
	}
	sort_five(g);
}

void	big_sort(t_global *g)
{
	int	nb_chunk;

	nb_chunk = (int)(ft_sqrt(g->size) / 1.6);
	complet_chunks(g, nb_chunk);
	sort_chunk(g);
}
