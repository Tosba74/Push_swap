/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:06:50 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/10 13:07:54 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	print_pic(void)
{
	dprintf(2, "                         \\\\||//                          \n");
	dprintf(2, "                          \\VV/                          \n");
	dprintf(2, "                           \\/                          \n");
}

void	print_maillon(t_list *a, t_list *b)
{
	t_info	*con;
	t_info	*con_a;
	t_info	*con_b;

	con = &(t_info){};
	if (!a->content)
		con_a = con;
	else
		con_a = a->content;
	if (!b->content)
		con_b = con;
	else
		con_b = b->content;
	dprintf(2, "*----------------------*--------*----------------------*\n");
	dprintf(2, "| %18p A | Maille | B %-18p |\n", a, b);
	dprintf(2, "*----------------------*--------*----------------------*\n");
	dprintf(2, "| %20p |  next  | %-20p |\n", a->next, b->next);
	dprintf(2, "| %20p |  cont  | %-20p |\n", a->content, b->content);
	dprintf(2, "| pos: %-5dnb: %-6d |  numb  | pos: %-5dnb: %-6d |\n",
		con_a->pos, con_a->nb, con_b->pos, con_b->nb);
	dprintf(2, "*----------------------*--------*----------------------*\n");
	if (a->next || b->next)
		print_pic();
}
*/

/*
	Print sur la sortie d'erreur le maillons pointer des listes chainees a et b,
	de la maniere suivant: "|a>| content.pos || content.pos |<b|"
	/!\ if ((a || b)->content == NULL){print("0");}
*/
void	print_maillon(t_list *a, t_list *b)
{
	t_info	*con;
	t_info	*con_a;
	t_info	*con_b;

	con = &(t_info){0};
	if (!a->content)
		con_a = con;
	else
		con_a = a->content;
	if (!b->content)
		con_b = con;
	else
		con_b = b->content;
	dprintf(2, "|a>| % 3d || % 3d |<b|\n", con_a->pos, con_b->pos);
}

void	print_list(t_global *g)
{
	int		i;
	t_list	*a;
	t_list	*b;

	i = -1;
	a = g->a;
	b = g->b;
	if (!a || !b)
	{
		dprintf(2, "%c est Null\n", !a?'A':'B');
		return ;
	}
	dprintf(2, "*--*-----**-----*--*\n");
	while (++i < g->size)
	{
		print_maillon(a, b);
		if (a->next)
			a = a->next;
		if (b->next)
			b = b->next;
	}
	dprintf(2, "*--*-----**-----*--*\n");
}

/*
	Print n nonbres d un int* sur la sortie d erreur  		
*/
void	print_array(int *array, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		dprintf(2, "|%d| ", array[i]);
	dprintf(2, "\n");
}
