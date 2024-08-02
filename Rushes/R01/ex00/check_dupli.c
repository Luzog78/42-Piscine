/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dupli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbreton <jbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:25:09 by ajasnin           #+#    #+#             */
/*   Updated: 2023/07/23 16:51:09 by jbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_dupli_col(int **tab, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (i != j && tab[x][i] != -1 && tab[x][j] != -1
				&& tab[x][i] == tab[x][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_dupli_row(int **tab, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (i != j && tab[i][y] != -1 && tab[j][y] != -1
				&& tab[i][y] == tab[j][y])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_dupli(int **tab)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (!ft_check_dupli_row(tab, i) || !ft_check_dupli_col(tab, i))
			return (0);
		i++;
	}
	return (1);
}
