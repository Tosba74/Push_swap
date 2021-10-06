/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/06 16:46:21 by bmangin          ###   ########lyon.fr   */
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
			rotate_b(&g->a, &g->b, g);
	else if (pos > size / 2)
	{
		size -= pos;
		while (size-- != 0)
			rev_rotate_b(&g->a, &g->b, g);
	}
	push_a(&g->a, &g->b, g);
}

static void	sort_chunk(t_global *g)
{
	int		wanted;

	wanted = get_position(&g->a);
	while (--wanted != 0)
	{
		// printf("wanted == %d\n", wanted);
		find_maillon(g, wanted);
		if (get_position(&g->a) == wanted)
	}
}

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
			imax = size - 2;
		// dprintf(2, "Chunk #%02d/%02d imax = %3d\n", index_chunk, nb_chunk, imax);
		while (i < imax)
		{
			// tmp = find_chunk(g, max_per_chunk);
			tmp = get_position(&g->a);
			// if (tmp == index_chunk)
			if (tmp < imax)
			{
				// dprintf(2, "PUSH in C#%d => %d/%d(%d)\n",
					// tmp, i, imax, get_position(&g->a));
				push_b(&g->a, &g->b, g);
				i++;
			}
			else
			{
				//dprintf(2, "REV :/ %d(%d)\n", tmp, get_position(&g->a));
				rev_rotate_a(&g->a, &g->b, g);
			}
		}
	}
	print_list(g);
	sort_five(g);
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

void	push_between_bounds(t_global *g, int bound_min, int bound_max)
{
	int		pos;
	int		size;
	t_list	*tmp;

	tmp = g->a;
	size = ft_lstsize(g->a);
	pos = 0;
	while (tmp)
	{
		if ((int)tmp->content >= bound_min && (int)tmp->content <= bound_max)
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

int	ft_maximum_number(t_list *b)
{
	int	max;
	int	index;
	int	index_r;

	index = 0;
	index_r = 0;
	max = (int)b->content;
	b = b->next;
	index++;
	while (b)
	{
		if ((int)b->content > max)
		{
			index_r = index;
			max = (int)b->content;
		}
		index++;
		b = b->next;
	}
	return (index_r);
}

void	push_on_stack_b(t_global *g, int *tab, int size)
{
	int	number_bounds;
	int	bound_min_i;
	int	bound_max_i;
	int	i;

	i = 0;
	bound_max_i = 0;
	bound_min_i = 0;
	number_bounds = ft_sqrt(g->size) / 1.5;
	while (i != number_bounds)
	{
		bound_min_i = size / number_bounds * i;
		if (i != 0)
			bound_min_i++;
		if (i == number_bounds - 1)
			bound_max_i = size - 1;
		else
			bound_max_i = size / number_bounds * (i + 1);
		push_between_bounds(g, tab[bound_min_i], tab[bound_max_i]);
		i++;
	}
}

void	push_max_a(t_global *g)
{
	int	max_pos;
	int	lstsize;

	lstsize = ft_lstsize(g->b);
	max_pos = ft_maximum_number(g->b);
	if (max_pos > (lstsize + 1) / 2)
		while (max_pos++ != lstsize)
			rev_rotate_b(&g->a, &g->b, g);
	else
		while (max_pos--)
			rotate_b(&g->a, &g->b, g);
	push_a(&g->a, &g->b, g);
}

void	big_sort(t_global *g)
{
	int	size;

	size = ft_lstsize(g->a);
	if (!a_is_sort(g->a))
		return ;
	push_on_stack_b(g, g->sorted, size);
	while (g->b)
		push_max_a(g);
}
*/

void	big_sort(t_global *g)
{
	int	nb_chunk;
	int	size;

	nb_chunk = (int)(ft_sqrt(g->size) / 1.6);
	size = ft_lstsize(g->a);
	if (verif_sort(g))
		return ;
	push_chunk_in_b(g, nb_chunk, size);
	print_list(g);
	sort_chunk(g);
	print_list(g);
}
