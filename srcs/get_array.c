/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:50:11 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/10 16:07:37 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_good_char(int c)
{
	if (c == ' ' || c == '-' || c == '+' || ft_isdigit(c))
		return (1);
	return (0);
}

static int	str_is_good(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (!is_good_char(s[i]))
			return (0);
	return (1);
}

static void	tabstr_to_array(char **av, t_global *g)
{
	int		i;

	i = -1;
	g->size = ft_strslen(av);
	g->array = (int *)wrmalloc(sizeof(int) * g->size);
	while (av[++i] && i < g->size)
	{
		if (!str_is_good(av[i]))
			ft_err("Arg: ", 1);
		g->array[i] = atoi_ov(av[i]);
	}
	if (ft_check_doublon(g->array, g->size) != 0)
		ft_err("Arg: ", 7);
}

static void	str_to_tab(char *av, t_global *g)
{
	char	**cheat;

	if (!str_is_good(av))
		ft_err("Arg: ", 1);
	cheat = ft_split(av, ' ');
	tabstr_to_array(cheat, g);
	wrfree(cheat);
}

void	get_array(int ac, char **av, t_global *g)
{
	if (ac == 2)
		str_to_tab(av[1], g);
	else if (ac > 2)
		tabstr_to_array(av + 1, g);
}
