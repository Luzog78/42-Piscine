/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:42:57 by ysabik            #+#    #+#             */
/*   Updated: 2023/08/02 19:53:57 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../include/bsq.h"

void	ft_init_map(t_map *map)
{
	map->height = -1;
	map->width = -1;
	map->empty = 0;
	map->obstacle = 0;
	map->full = 0;
	map->grid = 0;
	map->dist = 0;
}

/**
 * @returns	0 if the mallocs did well, else 1.
*/
int	ft_create_dist(t_map *map)
{
	int	current_line;

	map->dist = malloc(sizeof(int *) * map->height);
	if (map->dist == NULL)
		return (1);
	current_line = 0;
	while (current_line < map->height)
	{
		map->dist[current_line] = malloc(sizeof(int) * map->width);
		if (map->dist[current_line] == NULL)
		{
			current_line--;
			while (current_line >= 0)
			{
				free(map->dist[current_line]);
				current_line--;
			}
			free(map->dist);
			return (1);
		}
		current_line++;
	}
	return (0);
}

int	ft_free_those_before(t_map *map, int current_line, int free_dist, int err)
{
	if (current_line == -1)
		return (err);
	current_line--;
	while (current_line >= 0)
	{
		free(map->grid[current_line]);
		if (free_dist)
			free(map->dist[current_line]);
		current_line--;
	}
	free(map->grid);
	if (free_dist)
		free(map->dist);
	return (err);
}

void	ft_print_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		write(1, map.grid[i], map.width);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_fill(t_map *map, t_solution sol)
{
	t_pos	pos;

	pos.x = sol.pos.x;
	while (pos.x < sol.pos.x + sol.size)
	{
		pos.y = sol.pos.y;
		while (pos.y < sol.pos.y + sol.size)
		{
			map->grid[pos.y][pos.x] = map->full;
			pos.y++;
		}
		pos.x++;
	}
}
