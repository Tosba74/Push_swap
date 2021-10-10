/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:06:57 by bmangin           #+#    #+#             */
/*   Updated: 2021/10/10 16:11:51 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*msg_err(int err)
{
	static const char	*tab[] = {
	"PushSwap need an argument\n",
	"Bah char detected in argument\n",
	"Overflow !\n",
	"I need minimum two numbers for sort it! My friend\n",
	"Array Incorrect\n",
	"Maillon not find\n",
	"Already Sort\n",
	"Make sure yours arguments aren't same\n",
	"I can't help you =( Bro!\n",
	"Too big\n",
	"AH BAH DACCORD !!!\n"
	};

	return (tab[err]);
}

void	ft_err(char *s, int err)
{
	ft_putstr_fd("\033[31mError:\033[0m\n", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd((char *)msg_err(err), STDERR_FILENO);
	wrdestroy();
	exit(0);
}

static int	ft_check_ov(long num, int neg, int len)
{
	if (len >= 10)
	{
		if (neg == 1 && num > 2147483647)
			ft_err("Atoi return -1 INT_MAX: ", 2);
		else if (neg == -1 && num > 2147483648)
			ft_err("Atoi return 0 INT_MIN: ", 2);
	}
	return (num * neg);
}

int	atoi_ov(const char *str)
{
	int		neg;
	int		len;
	long	num;

	neg = 1;
	len = 0;
	num = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		len++;
		num = num * 10 + (*str++ - '0');
	}
	return (ft_check_ov(num, neg, len));
}

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb < 0)
		return (0);
	sqrt = 1;
	while (sqrt * sqrt <= nb)
		sqrt++;
	return (sqrt);
}
