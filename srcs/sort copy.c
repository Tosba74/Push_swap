/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/13 14:24:26 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next(t_list **lst, int needed, int size)
{
	int		i;
	t_list	*cpy;

	i = -1;
	cpy = *lst;
	while (++i <= size)
	{
		if (get_position(&(*lst)) == needed)
			return (i);
		(*lst) = (*lst)->next;
		i++;
	}
	*lst = cpy;
	return (-1);
}
	i = 0;
	pos = search_smaller(g, &i);
	dprintf(2, "pos = %d || i = %d\n", pos, i);
static void	push_smaller(t_global *g)
{
	int	i;
	int	pos;

	i = 0;
	pos = search_smaller(g, &i);
	dprintf(2, "pos = %d || i = %d\n", pos, i);
	if (pos <= i / 2)
	{
		while (pos-- != 0)
			rotate_a(&g->a, &g->b, g);
		push_b(&g->a, &g->b, g);
	}
	else if (pos > i / 2)
	{
		i -= pos;
		while (pos-- != 0)
			rev_rotate_a(&g->a, &g->b, g);
		push_b(&g->a, &g->b, g);
	}
}

void	rebuild_chunk(t_global *g, int mpc, int chunk, int *i)
{
	int	ret;
	int	min;
	int	max;


	ret = 0;
	if (*i == g->size - 1)
		min = g->size % chunk;
	else
		min = mpc;
	max = g->size - min;
	while (*i != max && *i != 0)
	{
		while (get_position(&g->b) == *i)
		{
			push_a(&g->a, &g->b, g);
			(*i)--;
			dprintf(2, "PUSH_A = %d next = %d\n", *i + 1, *i);
		}
		i = 0;
		pos = search_smaller(g, &i);
		dprintf(2, "pos = %d || i = %d\n", pos, i);
		// ret = find_next(&g->b, *i, min);
		// dprintf(2, "find_next ret = %d\n", ret);
		// if (ret < 0)
			// while (get_position(&g->b) != *i)
				// rev_rotate_b(&g->a, &g->b, g);
		// else
			// while (ret-- != 0)
				// rotate_b(&g->a, &g->b, g);
	}
}

void	sort_chunk(t_global *g, int nb_chunk)
{
	int	i;
	int	max_per_chunk;

	i = g->size - 1;
	max_per_chunk = (g->size) / nb_chunk;
	dprintf(2, "OOOOoooohhh\n");
	while (nb_chunk-- > 0)
	{	
		dprintf(2, "Chunk#%d => Max=%d | i => %d\n", nb_chunk, max_per_chunk, i);
		print_list(g);
		rebuild_chunk(g, max_per_chunk, nb_chunk, &i);
	}
}

static void	complet_chunks(t_global *g, int nb_chunk)
{
	int		i;
	int		index_chunk;
	int		max_per_chunk;

	i = 0;
	index_chunk = 0;
	max_per_chunk = (g->size) / nb_chunk;
	while (index_chunk++ < nb_chunk)
	{
		while ((i < (index_chunk * max_per_chunk) && i < g->size) || !a_is_sort(g->a))
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
	dprintf(2, "size => %d | nb => %d\n", g->size, nb_chunk);
	complet_chunks(g, nb_chunk);
	print_list(g);
	sort_chunk(g, nb_chunk);
	print_list(g);
}
