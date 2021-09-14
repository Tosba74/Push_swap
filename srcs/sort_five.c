/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/13 14:37:20 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Push dans b les deux plus petit nombre
*/
static int	search_smaller(t_global *g, int *i)
{
	int		ret;
	int		tmp;
	t_list	*cpy;

	ret = 0;
	cpy = g->a;
	tmp = g->size;
	while (g->a)
	{
		if (content_cmp(&g->a, tmp) < 0)
		{
			ret = *i;
			tmp = get_position(&g->a);
		}
		g->a = g->a->next;
		(*i)++;
	}
	g->a = cpy;
	return (ret);
}

static void	push_two_smaller(t_global *g)
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

void	sort_five(t_global *g)
{
	push_two_smaller(g);
	push_two_smaller(g);
	print_list(g);
	if (ft_lstsize(g->a) == 3)
		sort_three(g, 1);
	if (ft_lstsize(g->a) == 2)
		sort_two(g, 1);
	push_a(&g->a, &g->b, g);
	push_a(&g->a, &g->b, g);
}
