/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:59 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/07 20:53:50 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

/*
**	ra : rotate a décale d’une position vers le haut tous les élements
**	de la pile a. Le premier élément devient le dernier.
*/
void	rotate_a(t_global *g)
{
	rotate_list(&g->a);
	g->out = ft_strjoin_free(g->out, "ra\n", 1);
	g->coup++;
}

/*
**	rb : rotate b décale d’une position vers le haut tous les élements
**	de la pile b. Le premier élément devient le dernier.
*/
void	rotate_b(t_global *g)
{
	rotate_list(&g->b);
	g->out = ft_strjoin_free(g->out, "rb\n", 1);
	g->coup++;
}

/*
**	rr : ra et rb en même temps.
*/
void	rotate_r(t_global *g)
{
	rotate_list(&g->a);
	rotate_list(&g->b);
	g->out = ft_strjoin_free(g->out, "rr\n", 1);
	g->coup++;
}
