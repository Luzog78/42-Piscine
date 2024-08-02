/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbreton <jbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:33:06 by ltouzali          #+#    #+#             */
/*   Updated: 2023/07/23 16:50:20 by jbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_backtracking(int **tab, int *presets, int x, int y)
{
	int	choice;

	choice = 0;
	while (choice < SIZE)
	{
		ft_reset_following(tab, x, y);
		tab[x][y] = choice;
		if (ft_check_dupli(tab))
			if (ft_apply_recursivity(tab, presets, x, y))
				return (1);
		choice++;
	}
	return (0);
}

int	ft_apply_recursivity(int **tab, int *presets, int x, int y)
{
	if (y == SIZE - 1)
	{
		if (x == SIZE - 1)
		{
			if (ft_check_presets(presets, tab))
			{
				ft_write_array(tab);
				return (1);
			}
			else
				return (0);
		}
		else
			return (ft_backtracking(tab, presets, x + 1, 0));
	}
	else
		return (ft_backtracking(tab, presets, x, y + 1));
}
