/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:54:56 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/29 19:56:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

/**
 * @brief	Swap the VALUES of item A and item B.
 */
void	ft_swap(t_pair *a, t_pair *b)
{
	t_pair	c;

	c.name = a->name;
	c.nb = a->nb;
	a->name = b->name;
	a->nb = b->nb;
	b->name = c.name;
	b->nb = c.nb;
}

/**
 * @brief	Sort items of the given dict in DESCENDING way.
 */
void	ft_dict_sort(t_dict dict)
{
	int	i;

	i = 0;
	if (dict.len < 2)
		return ;
	while (i < dict.len - 1)
	{
		if (dict.items[i].nb < dict.items[i + 1].nb)
		{
			ft_swap(&dict.items[i], &dict.items[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
