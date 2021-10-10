/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:14:12 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/10 11:13:26by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	nothink(t_global *g)
{
	ft_err("Command not found: ", 8);
	(void)g;
}

int	find_action(char *line)
{
	char	*action[12];
	int		i;

	action[0] = "sa";
	action[1] = "sb";
	action[2] = "ss";
	action[3] = "pa";
	action[4] = "pb";
	action[5] = "rra";
	action[6] = "rrb";
	action[7] = "rrr";
	action[8] = "ra";
	action[9] = "rb";
	action[10] = "rr";
	action[11] = NULL;
	i = -1;
	while (action[++i])
		if (!(ft_strncmp(line, action[i], 3)))
			return (i);
	return (i);
}

void	do_action(t_global *g, char *line)
{
	int		index;
	void	(*pf_action[12])(t_global *g);

	pf_action[0] = &swap_a;
	pf_action[1] = &swap_b;
	pf_action[2] = &swap_s;
	pf_action[3] = &push_a;
	pf_action[4] = &push_b;
	pf_action[5] = &rev_rotate_a;
	pf_action[6] = &rev_rotate_b;
	pf_action[7] = &rev_rotate_r;
	pf_action[8] = &rotate_a;
	pf_action[9] = &rotate_b;
	pf_action[10] = &rotate_r;
	pf_action[11] = &nothink;
	index = find_action(line);
	pf_action[index](g);
}

void	checker(int ac, char **av)
{
	t_global	*g;
	char		*line;

	g = &(t_global){};
	init_global(ac, av, g);
	while (get_next_line(0, &line) > 0)
	{
		do_action(g, line);
		wrfree(line);
	}
	if (!verif_sort(g))
		ft_putstr("\033[32mOK\033[0m\n");
	else
		ft_putstr("\033[31mKO\033[0m\n");
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_err("PushSwap: ", 0);
	else
		checker(ac, av);
	wrdestroy();
	return (0);
}
