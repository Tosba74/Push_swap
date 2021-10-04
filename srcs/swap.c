/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:20 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/02 13:11:21 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
**	sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a.
**	Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	swap_a(t_list **a, t_list **b, t_global *g)
{
	(void)*b;
	swap_list(a);
	g->out = ft_strjoin_free(g->out, "sa\n", 1);
}

/*
**	sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b.
**	Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	swap_b(t_list **a, t_list **b, t_global *g)
{
	(void)*a;
	swap_list(b);
	g->out = ft_strjoin_free(g->out, "sb\n", 1);
}

/*
**	ss : sa et sb en même temps.
*/
void	swap_s(t_list **a, t_list **b, t_global *g)
{
	swap_list(a);
	swap_list(b);
	g->out = ft_strjoin_free(g->out, "ss\n", 1);
}
