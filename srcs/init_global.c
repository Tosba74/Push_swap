/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:45:31 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/07 20:56:05 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	is_already_sort(t_global *g)
// {
// 	int		i;

// 	i = 0;
// 	while (g->array[i] == g->sorted[i] && i < g->size)
// 		i++;
// 	if (g->array[i] != g->sorted[i])
// 		return (1);
// 	return (0);
// }

static int	find_index_sort(int *array, int needed)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
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
		pos = find_index_sort(g->sorted, g->array[i]);
		if (0 < pos && pos > 2147483647)
			ft_err("Sort: ", 4);
		else
			content->pos = pos;
		new = ft_lstnew(content);
		ft_lstadd_back(&g->a, new);
	}
	g->b = ft_lstnew(NULL);
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
