/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:30:05 by ysabik            #+#    #+#             */
/*   Updated: 2023/08/02 19:53:01 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/bsq.h"

int	ft_disgusting_free(t_map *map, char *line, int len, int *current_line)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
		{
			free(map->grid[*current_line]);
			return (8);
		}
		map->grid[*current_line][i] = line[i];
		i++;
	}
	return (0);
}
