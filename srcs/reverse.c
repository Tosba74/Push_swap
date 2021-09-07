/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:59 by bmangin           #+#    #+#             */
/*   Updated: 2021/08/17 14:08:04 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
**	rra : reverse rotate a décale d’une position vers le bas tous les élements
**	de la pile a. Le dernier élément devient le premier.
*/
void	rev_rotate_a(t_list **a, t_list **b, t_global *g)
{
	rev_rotate_list(a);
	(void)*b;
	g->out = ft_strjoin_free(g->out, "rra\n", 1);
}

/*
**	rrb : reverse rotate b - décale d’une position vers le bas tous les élements
**	de la pile b. Le dernier élément devient le premier.
*/
void	rev_rotate_b(t_list **a, t_list **b, t_global *g)
{
	(void)*a;
	rev_rotate_list(b);
	g->out = ft_strjoin_free(g->out, "rrb\n", 1);
}

/*
**	rrr : rra et rrb en même temps
*/
void	rev_rotate_r(t_list **a, t_list **b, t_global *g)
{
	rev_rotate_list(a);
	rev_rotate_list(b);
	g->out = ft_strjoin_free(g->out, "rrr\n", 1);
}
