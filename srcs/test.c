/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:06:50 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/07 11:47:30 by bmangin          ###   ########lyon.fr   */
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
			dprintf(STDOUT_FILENO, "\033[32ma>nb\033[0m\033[34m%5d\033[0m\033[32m|",
				((t_info *)(buf->content))->nb);
			dprintf(STDOUT_FILENO, "|\033[0m\033[34m%5d\033[0m\033[32mpos<a\033[0m\n",
				((t_info *)(buf->content))->pos);
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
			dprintf(STDOUT_FILENO, "\033[31ma>nb\033[0m\033[33m%5d\033[0m\033[31m|",
				((t_info *)(buf->content))->nb);
			dprintf(STDOUT_FILENO, "|\033[0m\033[33m%5d\033[0m\033[31mpos<a\033[0m\n",
				((t_info *)(buf->content))->pos);
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

/*
int		start_prepare_stacks(t_global *g)
{
	int	i;

	i = -1;
	if (!g->vizualizer)
	{
		if (g->action)
			printf("%s\n", g->action);
		return (-1);
	}
	while (++i < 299999999)
		;
	printf("\x1b[2J");
	printf("\x1b[H");
	printf("\e[0m|_______________|_______________|\n");
	printf("|\e[92m%-15s\e[0m|\e[93m%15s\e[0m|\n", "STACK A", "STACK B");
	printf("|_______________|_______________|\n");
	return (0);
}

void	print_stacks(t_global *g)
{
	int	i;

	i = -1;
	if (start_prepare_stacks(g) == -1)
		return ;
	while (++i < 9999999)
	{
		if (i > len(g->b) && i > len(g->a))
			break ;
		if (i < len(g->a))
			printf("|\e[92m%7s        \e[0m", g->a[len(g->a) - 1 - i]);
		else
			printf("|\e[92m%7s        \e[0m", "\0");
		if (i < len(g->b))
			printf("|\e[93m%7s        \e[0m|\n", g->b[len(g->b) - 1 - i]);
		else
			printf("|\e[93m%7s        \e[0m|\n", "\0");
	}
	printf("|_______________|_______________|\n");
	printf("| Coups = \033[0;32m%-6d\e[0m| Action = \033[0;35m%-5s\e[0m|\n",
		g->coups, g->action);
}
*/
