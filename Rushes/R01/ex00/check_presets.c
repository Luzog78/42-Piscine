/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_presets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbreton <jbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:57:19 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/23 16:51:25 by jbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief	Checks if all the numbers in the WHOLE BOARD respect the presets.
 * 
 * @param	presets	The game constraints
 * @param	tab		The game board
 * 
 * @returns	1 if the placement is correct, 0 otherwise.
*/
int	ft_check_presets(int *presets, int **tab)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (!ft_check_presets_col_asc(presets, tab, i)
			|| !ft_check_presets_col_desc(presets, tab, i)
			|| !ft_check_presets_line_asc(presets, tab, i)
			|| !ft_check_presets_line_desc(presets, tab, i))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief	Checks if all the numbers in the COLUMN respect the presets.
 * @note	VAR: `asc_count` means from UP to DOWN. (Y axis is inversed)
 * 
 * @param	presets	The game constraints
 * @param	tab		The game board
 * @param	x		The column we want to analysis
 * 
 * @returns	1 if the placement is correct, 0 otherwise.
*/
int	ft_check_presets_col_asc(int *presets, int **tab, int x)
{
	int	asc_count;
	int	count;
	int	height;
	int	i;

	asc_count = presets[x];
	count = 0;
	height = -1;
	i = 0;
	while (i < SIZE)
	{
		if (tab[x][i] > height)
		{
			height = tab[x][i];
			count++;
		}
		i++;
	}
	if (count != asc_count)
		return (0);
	return (1);
}

/**
 * @brief	Checks if all the numbers in the COLUMN respect the presets.
 * @note	VAR: `desc_count` means from DOWN to UP. (Y axis is inversed)
 * 
 * @param	presets	The game constraints
 * @param	tab		The game board
 * @param	x		The column we want to analysis
 * 
 * @returns	1 if the placement is correct, 0 otherwise.
*/
int	ft_check_presets_col_desc(int *presets, int **tab, int x)
{
	int	desc_count;
	int	count;
	int	height;
	int	i;

	desc_count = presets[x + SIZE];
	count = 0;
	height = -1;
	i = SIZE - 1;
	while (i >= 0)
	{
		if (tab[x][i] > height)
		{
			height = tab[x][i];
			count++;
		}
		i--;
	}
	if (count != desc_count)
		return (0);
	return (1);
}

/**
 * @brief	Checks if all the numbers in the ROW respect the presets.
 * @note	VAR: `asc_count` means from LEFT to RIGHT. (logic! isn't it?)
 * 
 * @param	presets	The game constraints
 * @param	tab		The game board
 * @param	y		The row we want to analysis
 * 
 * @returns	1 if the placement is correct, 0 otherwise.
*/
int	ft_check_presets_line_asc(int *presets, int **tab, int y)
{
	int	asc_count;
	int	count;
	int	height;
	int	i;

	asc_count = presets[y + SIZE * 2];
	count = 0;
	height = -1;
	i = 0;
	while (i < SIZE)
	{
		if (tab[i][y] > height)
		{
			height = tab[i][y];
			count++;
		}
		i++;
	}
	if (count != asc_count)
		return (0);
	return (1);
}

/**
 * @brief	Checks if all the numbers in the ROW respect the presets.
 * @note	VAR: `desc_count` means from RIGHT to LEFT. (logic! isn't it?)
 * 
 * @param	presets	The game constraints
 * @param	tab		The game board
 * @param	y		The row we want to analysis
 * 
 * @returns	1 if the placement is correct, 0 otherwise.
*/
int	ft_check_presets_line_desc(int *presets, int **tab, int y)
{
	int	desc_count;
	int	count;
	int	height;
	int	i;

	desc_count = presets[y + SIZE * 3];
	count = 0;
	height = -1;
	i = SIZE - 1;
	while (i >= 0)
	{
		if (tab[i][y] > height)
		{
			height = tab[i][y];
			count++;
		}
		i--;
	}
	if (count != desc_count)
		return (0);
	return (1);
}
