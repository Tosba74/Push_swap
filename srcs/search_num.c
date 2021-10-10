/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:33:53 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/09 20:44:39 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_bigger(t_global *g, int *i)
{
	int		ret;
	int		tmp;
	t_list	*cpy;

	ret = 0;
	tmp = 0;
	cpy = g->b;
	while (cpy)
	{
		if (((t_info *)(cpy->content))->pos > tmp)
		{
			ret = *i;
			tmp = ((t_info *)(cpy->content))->pos;
		}
		(*i)++;
		if (!cpy->next)
			break ;
		cpy = cpy->next;
	}
	return (ret);
}

void	push_bigger(t_global *g)
{
	int		size;
	int		pos;

	size = 0;
	pos = search_bigger(g, &size);
	if (pos != 0)
	{
		if (pos <= size / 2)
			while (pos-- != 0)
				rotate_b(g);
		else if (pos > size / 2)
		{
			size -= pos;
			while (size-- != 0)
				rev_rotate_b(g);
		}
	}
	push_a(g);
}

static int	search_smaller(t_global *g, int *i)
{
	int		ret;
	int		tmp;
	t_list	*cpy;

	ret = 0;
	tmp = g->size;
	cpy = g->a;
	while (cpy)
	{
		if (((t_info *)(cpy->content))->pos < tmp)
		{
			ret = *i;
			tmp = ((t_info *)(cpy->content))->pos;
		}
		(*i)++;
		if (!cpy->next)
			break ;
		cpy = cpy->next;
	}
	return (ret);
}

void	push_smaller(t_global *g)
{
	int		size;
	int		pos;

	size = 0;
	pos = search_smaller(g, &size);
	if (pos != 0)
	{
		if (pos <= size / 2)
			while (pos-- != 0)
				rotate_a(g);
		else if (pos > size / 2)
		{
			size -= pos;
			while (size-- != 0)
				rev_rotate_a(g);
		}
	}
	push_b(g);
}
