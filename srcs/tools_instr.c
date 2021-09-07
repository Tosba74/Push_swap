/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 01:30:47 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 09:50:12 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	swap_list(t_list **lst)
{
	t_info	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
}

void	push_list(t_list **add, t_list **remove)
{
	t_list	*tmp;

	if (!*remove)
		return ;
	tmp = *remove;
	*remove = (*remove)->next;
	tmp->next = *add;
	*add = tmp;
}

void	rotate_list(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	rev_rotate_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*begin;

	if (!*lst || !(*lst)->next || !(*lst)->next->next)
		return ;
	begin = *lst;
	tmp = ft_lstlast(*lst);
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	(*lst)->next = NULL;
	tmp->next = begin;
	*lst = tmp;
}
