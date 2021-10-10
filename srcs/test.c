/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:06:50 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/11 00:15:28 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_line(t_list *lst, char c)
{
	t_list	*x;

	x = lst;
	dprintf(2, "\033[31m-----\033[0m\n");
	while (x)
	{
		if (x->content)
		{
			dprintf(2, "\033[32m%c>nb%5d||%5d\033[0m\n", c,
				((t_info *)(x->content))->nb, ((t_info *)(x->content))->pos);
			x = x->next;
		}
		else
			break ;
	}
	dprintf(2, "\033[31m-----\033[0m\n");
}

void	print_list(t_global *g)
{
	if (!g->a)
	{
		dprintf(2, "A est Null\n");
		return ;
	}
	print_line(g->a, 'a');
	print_line(g->b, 'b');
}

void	print_array(int *array, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		dprintf(2, "|%d| ", array[i]);
	dprintf(2, "\n");
}
