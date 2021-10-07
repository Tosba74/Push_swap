/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/08 01:58:25 by bmangin          ###   ########lyon.fr   */
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
	// printf("size == %d pos == %d\n", size, pos);
	if (pos <= size / 2)
		while (pos-- != 0)
			rotate_b(g);
	else if (pos > size / 2)
	{
		size -= pos;
		while (size-- != 0)
			rev_rotate_b(g);
	}
	push_a(g);
}

static void	sort_chunk(t_global *g)
{
	int		wanted;

	wanted = get_position(&g->a);
	while (g->b)
	{
		// printf("wanted == %d\n", wanted);
		find_maillon(g, --wanted);
	}
	// push_a(g);
}

void	push_chunk_in_b(t_global *g, int nb_chunk, int size)
{
	int		i;
	int		index_chunk;
	int		max_per_chunk;
	int		imax;

	i = 0;
	index_chunk = 0;
	max_per_chunk = size / nb_chunk;
	while (++index_chunk < size)
	{
		imax = max_per_chunk * index_chunk;
		if (imax > size)
			imax = size - 4;
		// dprintf(2, "\033[32mChunk#%d for #<%d\n\033[0m", index_chunk, imax);
		while (i < imax && i < size - 4)
		{
			if (get_position(&g->a) < imax)
			{
				// dprintf(2, "%d pb\n", get_position(&g->a));
				push_b(g);
				i++;
			}
			else
			{
				// dprintf(2, "%d rra\n",get_position(&g->a));
				rev_rotate_a(g);
			}
		}
	}
	sort_five(g);
}

void	big_sort(t_global *g)
{
	int	nb_chunk;
	int	size;

	nb_chunk = (int)(ft_sqrt(g->size) / 1.6);
	size = ft_lstsize(g->a);
	// dprintf(2, "nb_chunk = %d | size = %d\n", nb_chunk, size);
	if (verif_sort(g))
		return ;
	push_chunk_in_b(g, nb_chunk, size);
	// print_list(g);
	sort_chunk(g);
	// print_list(g);
}
