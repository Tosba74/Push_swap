/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:20 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 11:07:13 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
	pa : push a - prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide.
*/
void	push_a(t_list **a, t_list **b, t_global *g)
{
	push_list(a, b);
	g->out = ft_strjoin_free(g->out, "pa\n", 1);
}

/*
	pb : push b - prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.
*/
void	push_b(t_list **a, t_list **b, t_global *g)
{
	push_list(b, a);
	g->out = ft_strjoin_free(g->out, "pb\n", 1);
}
