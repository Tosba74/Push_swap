/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:06:50 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/28 21:20:48 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_maillon(t_list *a, t_list *b)
{
	t_info	*con;
	t_info	*con_a;
	t_info	*con_b;

	con = &(t_info){0};
	if (!a->content)
		con_a = con;
	else
		con_a = a->content;
	if (!b->content)
		con_b = con;
	else
		con_b = b->content;
	dprintf(2, "| % 3d % 3d |<a||b>| % 3d % 3d |\n",
		con_a->pos, con_a->nb, con_b->pos, con_b->nb);
}

void	print_list(t_global *g)
{
	int		i;
	t_list	*a;
	t_list	*b;

	i = -1;
	a = g->a;
	b = g->b;
	if (!a)
	{
		dprintf(2, "%c est Null\n", 'A');
		return ;
	}
	if (!b)
	{
		dprintf(2, "%c est Null\n", 'B');
		return ;
	}
	while (++i < g->size)
	{
		print_maillon(a, b);
		if (a->next)
			a = a->next;
		if (b->next)
			b = b->next;
	}
}

void	print_array(int *array, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		dprintf(2, "|%d| ", array[i]);
	dprintf(2, "\n");
}
