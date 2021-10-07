/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:03:09 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/07 19:24:03 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_is_sort(t_list *lst)
{
	int		i;
	t_list	*cpy;

	i = get_position(&lst);
	cpy = lst;
	while (cpy)
	{
		if (content_cmp(&cpy, i) != 0)
		{
			return (1);
		}
		i++;
		cpy = (cpy)->next;
	}
	return (0);
}

int	verif_sort(t_global *g)
{
	int		i;
	t_list	*begin;

	i = -1;
	if (!g->a)
		ft_err("Stack A: ", 5);
	begin = g->a;
	while (++i < g->size)
	{
		if (((t_info *)(begin->content))->pos != i)
			return (0);
		begin = begin->next;
	}
	return (1);
}

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
