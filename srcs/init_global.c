/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:45:31 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/09 22:05:23 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index_sort(int *array, int needed, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (-1);
	while (i < n)
	{
		if (array[i] == needed)
			return (i);
		i++;
	}
	return (-1);
}

void	init_maillon(t_global *g)
{
	int		i;
	int		pos;
	t_list	*new;
	t_info	*content;

	i = -1;
	new = NULL;
	while (++i < g->size)
	{
		content = wrmalloc(sizeof(t_info) * 1);
		content->nb = g->array[i];
		pos = find_index_sort(g->sorted, g->array[i], g->size);
		if (0 < pos && pos > 2147483647)
			ft_err("Sort: ", 4);
		else
			content->pos = pos;
		new = ft_lstnew(content);
		ft_lstadd_back(&g->a, new);
	}
	g->b = NULL;
}

void	init_global(int ac, char **av, t_global *g)
{
	int	i;

	i = -1;
	get_array(ac, av, g);
	if (!g->array)
		ft_err("PushSwap: ", 3);
	g->coup = 0;
	g->vizualizer = 1;
	if (0 < g->size)
	{
		g->sorted = (int *)wrmalloc(sizeof(int) * g->size - 1);
		g->out = ft_strdup("");
		while (++i < g->size)
			g->sorted[i] = g->array[i];
		ft_bubble_sort(g->sorted, g->size);
		init_maillon(g);
	}
	else
		ft_err("Array: ", 4);
}
