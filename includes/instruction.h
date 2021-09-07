/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:52:00 by bmangin           #+#    #+#             */
/*   Updated: 2021/08/25 23:02:23 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

/*
| ******************************************************* |
| ****************   Struct Contentlst   **************** |
| ******************************************************* |
*/

typedef struct s_info
{
	int			nb;
	int			pos;
}				t_info;

/*
| ******************************************************* |
| ******************   Struct Global   ****************** |
| ******************************************************* |
*/

typedef struct s_global
{
	t_list		*a;
	t_list		*b;
	int			size;
	int			*array;
	int			*sorted;
	char		*out;
}				t_global;

/*
| ******************************************************* |
| ***************   Instructions Tools   **************** |
| ******************************************************* |
*/

void	swap_list(t_list **lst);
void	push_list(t_list **add, t_list **remove);
void	rotate_list(t_list **lst);
void	rev_rotate_list(t_list **lst);

/*
| ******************************************************* |
| ******************   Instructions   ******************* |
| ******************************************************* |
*/

void	swap_a(t_list **a, t_list **b, t_global *g);
void	swap_b(t_list **a, t_list **b, t_global *g);
void	swap_s(t_list **a, t_list **b, t_global *g);
void	push_a(t_list **a, t_list **b, t_global *g);
void	push_b(t_list **a, t_list **b, t_global *g);
void	rotate_a(t_list **a, t_list **b, t_global *g);
void	rotate_b(t_list **a, t_list **b, t_global *g);
void	rotate_r(t_list **a, t_list **b, t_global *g);
void	rev_rotate_a(t_list **a, t_list **b, t_global *g);
void	rev_rotate_b(t_list **a, t_list **b, t_global *g);
void	rev_rotate_r(t_list **a, t_list **b, t_global *g);

#endif

/*
** sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a.
** Ne fait rien s’il n’y en a qu’un ou aucun.
** sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b.
** Ne fait rien s’il n’y en a qu’un ou aucun.
** ss : sa et sb en même temps.
** pa : push a - prend le premier élément au sommet de b et le met sur a.
** Ne fait rien si b est vide.
** pb : push b - prend le premier élément au sommet de a et le met sur b.
** Ne fait rien si a est vide.
** ra : rotate a - décale d’une position vers le haut tous les élements de la 
** pile a. Le premier élément devient le dernier.
** rb : rotate b - décale d’une position vers le haut tous les élements de la
** pile b. Le premier élément devient le dernier.
** rr : ra et rb en même temps.
** rra : reverse rotate a - décale d’une position vers le bas tous les
** élements de la pile a. Le dernier élément devient le premier.
** rrb : reverse rotate b - décale d’une position vers le bas tous les
** élements de la pile b. Le dernier élément devient le premier.
** rrr : rra et rrb en même temps
*/