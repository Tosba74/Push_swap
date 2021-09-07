/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 10:49:01 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Verifie le classement en comparant l'index et la position des maillons
	return 0 si le classement est faux 1 si c est bon
*/
int	verif_sort(t_global *g)
{
	int		i;
	t_list	*begin;
	t_info	*content;

	i = -1;
	begin = g->a;
	if (g->b != NULL)
		return (0);
	while (++i < g->size)
	{
		content = g->a->content;
		if (content->pos != i)
			return (0);
		g->a = g->a->next;
	}
	return (1);
}

/*
	Compare le premier et le deuxieme element de la pile.
	return second.pos - first.pos
*/
int	where_am_i(t_list **lst, int neg)
{
	t_info	*first;
	t_info	*second;

	if (!(*lst) || !(*lst)->next)
		ft_err("List: ", 5);
	first = (*lst)->content;
	second = (*lst)->next->content;
	return ((second->pos - first->pos) * neg);
}

/*
	Verifie que les n maillons soit classe
	Return 1 si c'est le cas, 0 en cas erreur.
*/
int	lst_is_sort(t_list **lst, int n)
{
	int		i;
	t_list	*check;

	i = -1;
	check = *lst;
	if (n <= 0)
		return (0);
	while (++i < n - 1)
	{
		if (where_am_i(&check, 1) > 0)
			check = check->next;
		else
			return (0);
	}
	return (1);
}
