/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:06:50 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/06 19:05:44 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_maillon(t_list *a, t_list *b)
{
	t_info	*con;
	t_info	*con_a;
	t_info	*con_b;

	con = &(t_info){0};
	if (!a || !a->content)
		con_a = con;
	else
		con_a = a->content;
	if (!b || !b->content)
		con_b = con;
	else
		con_b = b->content;
	dprintf(2, "| %03d %03d |<a||b>| %03d %03d |\n",
		con_a->pos, con_a->nb, con_b->pos, con_b->nb);
}

void	print_list(t_global *g)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*buf;

	i = -1;
	a = g->a;
	b = g->b;
	if (!a)
	{
		dprintf(2, "%c est Null\n", 'A');
		return ;
	}
	// if (!b)
	// {
	// 	dprintf(2, "%c est Null\n", 'B');
	// 	return ;
	// }
	// while (a)
	// {
	// 	print_maillon(a, b);
	// 	if (a->next)
	// 		a = a->next;
	// 	if (b->next)
	// 		b = b->next;
	// }
	buf = g->a;
	while (buf)
	{
		if (buf->content)
		{
			dprintf(STDOUT_FILENO, "\033[32ma>nb\033[0m\033[34m%3d \033[0m\033[32m||\033[0m\033[34m%3d\033[0m\033[32m pos<a\033[0m\n",
				((t_info *)(buf->content))->nb, ((t_info *)(buf->content))->pos);
			buf = buf->next;
		}
		else
			break ;
	}
	buf = g->b;
	while (buf)
	{
		if (buf->content)
		{
			dprintf(STDOUT_FILENO, "\033[31ma>nb\033[0m\033[33m%3d \033[0m\033[31m||\033[0m\033[33m%3d\033[0m\033[31m pos<a\033[0m\n",
				((t_info *)(buf->content))->nb, ((t_info *)(buf->content))->pos);
			buf = buf->next;
		}
		else
			break ;
	}
}

void	print_array(int *array, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		dprintf(2, "|%d| ", array[i]);
	dprintf(2, "\n");
}
