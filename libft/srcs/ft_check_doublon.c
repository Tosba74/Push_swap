/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_doublon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:11:24 by bmangin           #+#    #+#             */
/*   Updated: 2021/09/06 16:05:51 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Find same int in int *array, retrun 1 if you have same int and 0 if not
	Return -1 if array or size is NULL.
*/
int	ft_check_doublon(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (size == 0 || tab == NULL)
		return (ERROR);
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] == tab[j] && i != j)
				return (FAILURE);
			j++;
		}
		j = 0;
		i++;
	}
	return (SUCCESS);
}
