/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 14:47:55 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Return la difference entre un int donne et a la content.nb
	Donc 0 s'il sont identiques.
*/
int	content_cmp(t_list **lst, int cmp)
{
	t_info	*content;

	if (!(*lst) || !(*lst)->content)
		return (0);
	content = (*lst)->content;
	return (content->pos - cmp);
}

/*
	Return le content.pos du maillons pointer
	Ne sert pas actuellement
*/
int	get_position(t_list **lst)
{
	t_info	*content;

	content = (*lst)->content;
	return (content->pos);
}

/*
	Tri deux premier elements.
	Si neg = 1 Tri croissant des deux premier elements de la liste A
	Si neg = -1 Tri decroissant des deux premier elements de la liste B
*/
void	sort_two(t_global *g, int neg)
{
	int	pos;

	if (neg > 0)
	{
		pos = where_am_i(&g->a, neg);
		dprintf(2, "Pos = %d\n", pos);
		if (pos < 0)
			swap_a(&g->a, &g->b, g);
	}
	else if (neg < 0)
	{
		pos = where_am_i(&g->b, neg);
		dprintf(2, "Pos = %d\n", pos);
		if (pos < 0)
			swap_b(&g->a, &g->b, g);
	}
}

/*
	Tri une pile de trois elements, suivant le schema suivant:
	https://miro.medium.com/max/1400/1*D0U1zQFQnkI4Q_Z0QPi69g.png
*/
void	sort_three(t_global *g, int neg)
{
	int		first;
	int		second;

	first = where_am_i(&g->a, neg);
	second = where_am_i(&g->a->next, neg);
	if (!lst_is_sort(&g->a, 3))
	{
		if (first > 0 && second < 0 && first < second * -1)
			rev_rotate_a(&g->a, &g->b, g);
		else if (first < 0 && second > 0 && first * -1 > second)
			rotate_a(&g->a, &g->b, g);
		else
		{
			swap_a(&g->a, &g->b, g);
			if (!lst_is_sort(&g->a, 3))
			{
				if (where_am_i(&g->a, neg) < 0)
					rotate_a(&g->a, &g->b, g);
				else
					rev_rotate_a(&g->a, &g->b, g);
			}
		}
	}
}
