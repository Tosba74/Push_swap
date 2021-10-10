/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:52:00 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/11 00:15:20 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"
# include "instruction.h"

/* ******************************************************* */
/* ********************   Sort   ************************* */
/* ******************************************************* */
void	choose_sort(t_global *g, int size);
void	big_sort(t_global *g);

/* ******************************************************* */
/* ******************  Small Sort   ********************** */
/* ******************************************************* */
void	sort_two(t_global *g, int neg);
void	sort_three(t_global *g, int neg);
void	sort_five(t_global *g);

/* ******************************************************* */
/* *****************  Tools Search   ********************* */
/* ******************************************************* */

void	push_smaller(t_global *g);
void	push_bigger(t_global *g);

/* ******************************************************* */
/* ******************  Tools Sort   ********************** */
/* ******************************************************* */
int		a_is_sort(t_list *lst);
int		where_am_i(t_list **lst, int neg);
int		verif_sort(t_global *g);
int		lst_is_sort(t_list **lst, int n);
// int		search_smaller(t_global *g, int *i);

/* ******************************************************* */
/* ****************  Test List&Array   ******************* */
/* ******************************************************* */
void	print_list(t_global *g);
void	print_array(int *array, int size);

/* ******************************************************* */
/* *******************   Tools   ************************* */
/* ******************************************************* */
void	ft_err(char *s, int err);
int		atoi_ov(const char *str);
int		ft_sqrt(int nb);

/* ******************************************************* */
/* ********************   Tools   ************************ */
/* ******************************************************* */
void	init_global(int ac, char **av, t_global *g);

/* ******************************************************* */
/* ******************   Get_Array   ********************** */
/* ******************************************************* */
void	get_array(int ac, char **av, t_global *g);

#endif
