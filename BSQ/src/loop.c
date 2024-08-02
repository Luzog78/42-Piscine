/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:06:24 by ysabik            #+#    #+#             */
/*   Updated: 2023/08/02 19:54:48 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/bsq.h"
#include "../include/utils.h"

int		ft_get_min(t_map *map, t_pos pos);
void	ft_update_solution(t_solution *sol, t_pos pos, int min);

int	ft_solution(t_map *map, t_solution *sol)
{
	t_pos		pos;
	int			min;

	min = 0;
	ft_init_pos(&pos, 0, 0);
	ft_init_sol(sol, 0, 0, 0);
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			if (map->grid[pos.y][pos.x] == map->obstacle)
				map->dist[pos.y][pos.x] = 0;
			else
			{
				min = ft_get_min(map, pos);
				map->dist[pos.y][pos.x] = min + 1;
				ft_update_solution(sol, pos, min);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (sol->size != 0);
}

int	ft_get_min(t_map *map, t_pos pos)
{
	int	min;

	if (!pos.x || !pos.y)
		return (0);
	min = map->dist[pos.y - 1][pos.x - 1];
	if (map->dist[pos.y - 1][pos.x] < min)
		min = map->dist[pos.y - 1][pos.x];
	if (map->dist[pos.y][pos.x - 1] < min)
		min = map->dist[pos.y][pos.x - 1];
	return (min);
}

void	ft_update_solution(t_solution *sol, t_pos pos, int min)
{
	if (min + 1 > sol->size)
	{
		sol->size = min + 1;
		sol->pos.y = pos.y - min;
		sol->pos.x = pos.x - min;
	}
}
