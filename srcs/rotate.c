/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:59 by bmangin           #+#    #+#             */
/*   Updated: 2021/08/17 14:11:49 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
**	ra : rotate a décale d’une position vers le haut tous les élements
**	de la pile a. Le premier élément devient le dernier.
*/
void	rotate_a(t_list **a, t_list **b, t_global *g)
{
	(void)*b;
	rotate_list(a);
	g->out = ft_strjoin_free(g->out, "ra\n", 1);
}

/*
**	rb : rotate b décale d’une position vers le haut tous les élements
**	de la pile b. Le premier élément devient le dernier.
*/
void	rotate_b(t_list **a, t_list **b, t_global *g)
{
	(void)*a;
	rotate_list(b);
	g->out = ft_strjoin_free(g->out, "rb\n", 1);
}

/*
**	rr : ra et rb en même temps.
*/
void	rotate_r(t_list **a, t_list **b, t_global *g)
{
	rotate_list(a);
	rotate_list(b);
	g->out = ft_strjoin_free(g->out, "rr\n", 1);
}
