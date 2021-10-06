/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/06 14:10:18 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_bigger(t_global *g, int needed, int *i)
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
	pos = search_bigger(g, needed, &size);
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
	while (g->b && i >= 0)
	{
		find_maillon(g, i);
		if (get_position(&g->b) == i)
			push_a(&g->a, &g->b, g);
		i--;
	}
	push_a(&g->a, &g->b, g);
}

/*
void	put_number_on_the_top(t_global *g, int pos, int size)
{
	if (pos < (size + 1) / 2)
		while (pos-- > 0)
			rotate_a(&g->a, &g->b, g);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rev_rotate_a(&g->a, &g->b, g);
	}
	push_b(&g->a, &g->b, g);
}

void	push_in_chunk(t_global *g, int chunk_min, int chunk_max)
{
	int		pos;
	int		size;
	t_list	*tmp;

	tmp = g->a;
	size = ft_lstsize(g->a);
	pos = 0;
	while (tmp)
	{
		if ((int)tmp->content >= chunk_min && (int)tmp->content <= chunk_max)
		{
			put_number_on_the_top(g, pos, size);
			tmp = g->a;
			pos = -1;
		}
		else
			tmp = tmp->next;
		pos++;
	}
}
static void	complet_chunks(t_global *g, int **tab, int nb_chunk)
{
	int	chunk_min_i;
	int	chunk_max_i;
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(g->a);
	chunk_max_i = 0;
	chunk_min_i = 0;
	while (i != nb_chunk)
	{
		chunk_min_i = size / nb_chunk * i;
		if (i != 0)
			chunk_min_i++;
		if (i == nb_chunk - 1)
			chunk_max_i = size - 1;
		else
			chunk_max_i = size / nb_chunk * (i + 1);
		push_in_chunk(g, *tab[chunk_min_i], *tab[chunk_max_i]);
		i++;
	}
}
*/

static void	complet_chunks(t_global *g, int nb_chunk, int size)
{
	int		i;
	int		index_chunk;
	int		max_per_chunk;
	int		max_chunk;
	int		num;

	i = 0;
	index_chunk = 1;
	max_per_chunk = size / nb_chunk;
	dprintf(2, "List de %d elements soit:\n%d Chunk de %d, et un dernier de %d\n",
		size, nb_chunk, max_per_chunk, size - max_per_chunk * (nb_chunk));
	while (index_chunk <= nb_chunk + 1)
	{
		max_chunk = max_per_chunk * index_chunk;
		if (max_chunk > size)
			max_chunk = size - 3;
		dprintf(2, "#%d Chunks max = %d\n", index_chunk, max_chunk);
		while ((i <= max_chunk && i < size - 3) || !a_is_sort(g->a))
		{
			num = get_position(&g->a);
			dprintf(2, "num = %3d\n", num);
			if (num > max_chunk)
			{
				dprintf(2, "num = %3d || ra\n", num);
				rotate_a(&g->a, &g->b, g);
			}
			else
			{
				dprintf(2, "num = %3d || pb\n", num);
				push_b(&g->a, &g->b, g);
				i++;
			}
		}
		index_chunk++;
	}
	choose_sort(g, 5);
}

// static void	complet_chunks(t_global *g, int nb_chunk)
// {
	// int		i;
	// int		index_chunk;
	// int		max_per_chunk;
// 
	// i = 0;
	// index_chunk = 0;
	// max_per_chunk = g->size / nb_chunk;
	// while (index_chunk++ != nb_chunk)
	// {
		// while ((i <= (index_chunk * max_per_chunk) && i < g->size - 3)
			// || !a_is_sort(g->a))
		// {
			// if (content_cmp(&g->a, (index_chunk * max_per_chunk)) <= 0)
			// {
				// push_b(&g->a, &g->b, g);
				// i++;
			// }
			// else
				// rotate_a(&g->a, &g->b, g);
		// }
	// }
	// if (a_is_sort(g->a))
		// sort_five(g);
// }

void	big_sort(t_global *g)
{
	int	nb_chunk;
	int	size;

	nb_chunk = (int)(ft_sqrt(g->size) / 1.6);
	size = ft_lstsize(g->a);
	if (verif_sort(g))
		return ;
	complet_chunks(g, nb_chunk, size);
	sort_chunk(g);
}
