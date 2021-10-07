/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:50:31 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/08 01:50:11 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_global *g, int size)
{
	if (size == 2)
		sort_two(g, 1);
	else if (size == 3)
		sort_three(g, 1);
	else if (size <= 5)
		sort_five(g);
	else if (size > 5)
		big_sort(g);
	else if (size > 500)
		ft_err("Size: ", 9);
}

void	push_swap(int ac, char **av)
{
	t_global	*g;

	g = &(t_global){};
	init_global(ac, av, g);
	if (!verif_sort(g))
		choose_sort(g, g->size);
	// print_stacks(g);
	// if (!verif_sort(g))
		// ft_err("Bad news: ", 8);
	ft_putstr(g->out);
	// print_list(g);
	// print_array(g->sorted, g->size);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_err("PushSwap: ", 0);
	else
		push_swap(ac, av);
	return (0);
}
