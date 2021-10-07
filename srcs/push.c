/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:20 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/07 20:53:41 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
	pa : push a - prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide.
*/
void	push_a(t_global *g)
{
	push_list(&g->a, &g->b);
	g->out = ft_strjoin_free(g->out, "pa\n", 1);
	g->coup++;
}

/*
	pb : push b - prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.
*/
void	push_b(t_global *g)
{
	push_list(&g->b, &g->a);
	g->out = ft_strjoin_free(g->out, "pb\n", 1);
	g->coup++;
}
