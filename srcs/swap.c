/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:20 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/07 20:54:11 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
**	sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a.
**	Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	swap_a(t_global *g)
{
	swap_list(&g->a);
	g->out = ft_strjoin_free(g->out, "sa\n", 1);
	g->coup++;
}

/*
**	sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b.
**	Ne fait rien s’il n’y en a qu’un ou aucun.
*/
void	swap_b(t_global *g)
{
	swap_list(&g->b);
	g->out = ft_strjoin_free(g->out, "sb\n", 1);
	g->coup++;
}

/*
**	ss : sa et sb en même temps.
*/
void	swap_s(t_global *g)
{
	swap_list(&g->a);
	swap_list(&g->b);
	g->out = ft_strjoin_free(g->out, "ss\n", 1);
	g->coup++;
}
