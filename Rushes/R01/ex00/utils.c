/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbreton <jbreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:16:51 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/23 16:48:19 by jbreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief	Construct the presets table
 * 
 * @param	str	The argument to find into
 * 
 * @returns Preset table (int *) (len=SIZE*4) or ((void *)0) in case of error
*/
int	*ft_fetch_presets(char *str)
{
	int	*preset;
	int	i;

	preset = malloc(sizeof(int) * SIZE * 4);
	if (preset == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			preset[i / 2] = str[i] - '0';
			if (preset[i / 2] <= 0 || preset[i / 2] > SIZE)
				return (0);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (i != SIZE * 4 * 2 - 1)
		return (0);
	return (preset);
}

int	**ft_create_2d_array(void)
{
	int	i;
	int	**arr;

	arr = malloc(SIZE * sizeof(int *));
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < SIZE)
	{
		arr[i] = malloc(SIZE * sizeof(int));
		if (arr[i] == NULL)
		{
			i--;
			while (i >= 0)
			{
				free(arr[i]);
				i--;
			}
			free(arr);
			return (0);
		}
		i++;
	}
	return (arr);
}

void	ft_free_2d_array(int **arr)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_write_array(int **arr)
{
	int	y;
	int	x;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			write(1, &(char){arr[x][y] + 1 + '0'}, 1);
			if (x != SIZE - 1)
			{
				write(1, " ", 1);
			}
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	ft_reset_following(int **arr, int x, int y)
{
	while (x < SIZE)
	{
		while (y < SIZE)
		{
			arr[x][y] = -1;
			y++;
		}
		x++;
		y = 0;
	}
}
