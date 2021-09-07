/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:52:00 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 19:41:36 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "libft.h"
# include "instruction.h"

/*
| ******************************************************* |
| ****************   Test List&Array   ****************** |
| ******************************************************* |
*/
void	print_list(t_global *g);
void	print_array(int *array, int size);
void	print_maillon(t_list *a, t_list *b);

/*
| ******************************************************* |
| ********************   Tools   ************************ |
| ******************************************************* |
*/
void	ft_err(char *s, int err);
int		atoi_ov(const char *str);
int		ft_sqrt(int nb);

/*
| ******************************************************* |
| ******************   Tools Sort   ********************* |
| ******************************************************* |
*/
int		content_cmp(t_list **lst, int cmp);
int		where_am_i(t_list **lst, int neg);
int		verif_sort(t_global *g);
int		get_position(t_list **lst);
int		lst_is_sort(t_list **lst, int n);

/*
| ******************************************************* |
| ******************   Small Sort   ********************* |
| ******************************************************* |
*/
void	sort_two(t_global *g, int neg);
void	sort_three(t_global *g, int neg);
void	sort_five(t_global *g);

/*
| ******************************************************* |
| *********************   Sort   ************************ |
| ******************************************************* |
*/
void	big_sort(t_global *g);
// void	sort_cent(t_global *g, int neg);
// void	others_sort(t_global *g);
/*
| ******************************************************* |
| *********************   Tools   *********************** |
| ******************************************************* |
*/
void	init_global(int ac, char **av, t_global *g);

/*
| ******************************************************* |
| *******************   Get_Array   ********************* |
| ******************************************************* |
*/
void	get_array(int ac, char **av, t_global *g);

#endif
