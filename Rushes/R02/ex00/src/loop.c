/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:56:00 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/30 22:33:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "libft.h"

void	ft_loop(unsigned long long n, t_dict dict, int depth);
void	ft_print_nums(unsigned long long n, t_dict dict, int depth, t_pair	p);

int	occ_0(unsigned long long i)
{
	int	occ;

	occ = 0;
	while (i > 1)
	{
		if (i % 10)
			return (-1);
		occ++;
		i /= 10;
	}
	return (occ);
}

int	check0s(unsigned long long i, t_bool put_ones)
{
	int	occ;

	occ = 0;
	while (i > 1)
	{
		if (i % 10)
			return (-1);
		occ++;
		i /= 10;
	}
	if (occ == -1)
		return (0);
	if (put_ones == TRUE)
		return (i == 1 && (occ % 3 == 0 || occ == 2));
	else
		return (i == 1 && occ % 3 == 0 && (occ > 3 || occ == 0));
}

void	ft_loop(unsigned long long n, t_dict dict, int depth)
{
	int		i;
	t_pair	p;

	i = 0;
	while (i < dict.len)
	{
		p = dict.items[i];
		if (p.nb == 0)
			ft_putstr(p.name);
		else if (n / p.nb != 0)
		{
			ft_print_nums(n, dict, depth, p);
			return ;
		}
		i++;
	}
}

void	ft_print_nums(unsigned long long n, t_dict dict, int depth, t_pair	p)
{
	unsigned long long	div;
	unsigned long long	result;

	div = n / p.nb;
	result = n - div * p.nb;
	if (div != 1 || (check0s(p.nb, dict.put_ones) && p.nb >= 100))
	{
		ft_loop(div, dict, depth);
		depth++;
	}
	if (depth)
		ft_putchar(' ');
	ft_putstr(p.name);
	if (dict.put_hyphen == TRUE && n < 100 && result != 0 && result < 10)
	{
		ft_putchar('-');
		depth = -1;
	}
	if (dict.put_comma == TRUE && occ_0(p.nb) % 3 == 0
		&& occ_0(p.nb) != 0 && result != 0)
		ft_putchar(',');
	if (result != 0)
		ft_loop(result, dict, depth + 1);
}
