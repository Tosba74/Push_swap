/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:50:31 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/28 21:25:14 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	last_verif(t_global *g)
// {
// 	int		i;
// 	t_list	*winner;

// 	i = -1;
// 	if (ft_lstsize(g->a) != g->size || !g->a)
// 		return (0);
// 	winner = g->a;
// 	while (winner->next)
// 	{
// 		if (content_cmp(&winner, ++i) != 0)
// 			return (0);
// 		winner = winner->next;
// 	}
// 	return (1);
// }

void	choose_sort(t_global *g, int size)
{
	if (size == 2)
		sort_two(g, 1);
	else if (size == 3)
		sort_three(g, 1);
	else if (size <= 5)
		sort_five(g);
	else
		big_sort(g);
}

void	push_swap(int ac, char **av)
{
	t_global	*g;

	g = &(t_global){};
	init_global(ac, av, g);
	choose_sort(g, g->size);
	// if (!last_verif(g))
	// 	ft_err("Bad news: ", 8);
	ft_putstr(g->out);
	// print_list(g);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_err("PushSwap: ", 0);
	else
		push_swap(ac, av);
	return (0);
}
