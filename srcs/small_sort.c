/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/11 00:25:29 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_global *g, int neg)
{
	int	pos;

	if (neg > 0)
	{
		pos = where_am_i(&g->a, neg);
		if (pos < 0)
			swap_a(g);
	}
	else if (neg < 0)
	{
		pos = where_am_i(&g->b, neg);
		if (pos < 0)
			swap_b(g);
	}
}

void	sort_three(t_global *g, int neg)
{
	int		first;
	int		second;

	first = where_am_i(&g->a, neg);
	second = where_am_i(&g->a->next, neg);
	if (!lst_is_sort(&g->a, 3))
	{
		if (first > 0 && second < 0 && first < second * -1)
			rev_rotate_a(g);
		else if (first < 0 && second > 0 && first * -1 > second)
			rotate_a(g);
		else
		{
			swap_a(g);
			if (!lst_is_sort(&g->a, 3))
			{
				if (where_am_i(&g->a, neg) < 0)
					rotate_a(g);
				else
					rev_rotate_a(g);
			}
		}
	}
}

void	sort_five(t_global *g)
{
	push_smaller(g);
	push_smaller(g);
	if (ft_lstsize(g->a) == 3)
		sort_three(g, 1);
	if (ft_lstsize(g->a) == 2)
		sort_two(g, 1);
	push_a(g);
	push_a(g);
}
