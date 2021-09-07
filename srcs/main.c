/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:50:31 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 20:04:09 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Verifie que les n maillons egale au g->sorted
	Return 1 si c'est le cas 0 en cas erreur
*/
static int	last_verif(t_global *g)
{
	int		i;
	t_list	*winner;

	i = -1;
	if (ft_lstsize(g->a) != g->size || !g->a)
		return (0);
	winner = g->a;
	while (winner->next)
	{
		if (content_cmp(&winner, ++i) != 0)
			return (0);
		winner = winner->next;
	}
	return (1);
}

static void	choose_sort(t_global *g)
{
	if (g->size == 2)
		sort_two(g, 1);
	else if (g->size == 3)
		sort_three(g, 1);
	else if (g->size <= 5)
		sort_five(g);
	else
		big_sort(g);
	// else if (g->size <= 10)
	// 	printf("OOOhhh sa fait beaucoup la nan ? -10nb\n");
	// else if (g->size <= 50)
	// 	printf("OOOhhh sa fait beaucoup la nan ? -50nb\n");
	// else if (g->size <= 100)
	// 	sort_cent(g, 1);
	// else if (g->size <= 500)
	printf("OOOhhh sa fait beaucoup la nan ? -500nb\n");
}

void	push_swap(int ac, char **av)
{
	t_global	*g;

	g = &(t_global){};
	init_global(ac, av, g);
	dprintf(2, "*----------------------------*\n");
	print_array(g->array, g->size);
	print_array(g->sorted, g->size);
	dprintf(2, "%d\n", g->size);
	print_list(g);
	// push_a(&g->a, &g->b, g);
	// push_a(&g->a, &g->b, g);
	// print_list(g);
	// sort_two(g, -1);
	choose_sort(g);
	ft_putstr(g->out);
	print_list(g);
	print_array(g->sorted, g->size);
	if (!last_verif(g))
		ft_err("Bad news: ", 8);
	dprintf(2, "OOOOoooohhh\n");
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_err("PushSwap: ", 0);
	else
		push_swap(ac, av);
	return (0);
}
