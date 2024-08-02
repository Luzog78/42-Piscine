/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:03:40 by ysabik            #+#    #+#             */
/*   Updated: 2023/08/02 20:08:57 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/bsq.h"
#include "../include/utils.h"

int		ft_read_file(t_map *map, int fd, char *line, int *current_line);
int		ft_setup_presets(t_map *map, char *line, int *current_line);
int		ft_setup_line(t_map *map, char *line, int *current_line);
void	ft_reset_line(char *line, int *index, int *err);

/**
 * @param	map		The map to setup
 * @param	file	The file to look into (`NULL` to stdin)
 * 
 * @returns	0	-	Fine !
 * 		||	1	-	Can't open.
 * 		||	2	-	Can't read.
 * 		||	3	-	Malloc err.
 * 		||	4	-	Map err - bad presets.
 * 		||	5	-	Map err - duplicated presets.
 * 		||	6	-	Map err - wrong line count.
 * 		||	7	-	Map err - wrong line lenght.
 * 		||	8	-	Map err - unknown or 'full' character in the map.
 * 		||	9	-	Map err - different line lenght.
 * 		||	10	-	Map err - different line count.
*/
int	ft_parse_map(t_map *map, char *file)
{
	int		fd;
	char	line[LINE_LIMIT];
	int		current_line;
	int		err;

	if (file != NULL)
	{
		fd = open(file, O_RDWR);
		if (fd == -1)
			return (1);
	}
	else
		fd = 0;
	ft_reset_line(line, &current_line, &err);
	current_line = -1;
	err = ft_read_file(map, fd, line, &current_line);
	if (err != 0)
		return (err);
	if (current_line == map->height)
	{
		if (ft_create_dist(map))
			return (3);
		return (0);
	}
	return (ft_free_those_before(map, current_line, 0, 10));
}

int	ft_read_file(t_map *map, int fd, char *line, int *current_line)
{
	char	buff;
	int		index;
	int		err;
	int		result;

	ft_reset_line(line, &index, &err);
	while (fd != 0 || *current_line < map->height || *current_line == -1)
	{
		result = read(fd, &buff, 1);
		if (result <= 0)
			close(fd);
		if (result <= 0)
			return ((result == -1) * 2);
		if (buff != '\n')
			line[index++] = buff;
		else if (*current_line == -1)
			err = ft_setup_presets(map, line, current_line);
		else
			err = ft_setup_line(map, line, current_line);
		if (err != 0)
			return (ft_free_those_before(map, *current_line, 0, err));
		if (buff == '\n')
			ft_reset_line(line, &index, &err);
	}
	return (0);
}

int	ft_setup_presets(t_map *map, char *line, int *current_line)
{
	int	idx;

	idx = ft_strlen(line) - 1;
	if (idx < 3)
		return (4);
	if (line[idx] < 32 || line[idx] > 126 || line[idx - 1] < 32 
		|| line[idx - 1] > 126 || line[idx - 2] < 32 || line[idx - 2] > 126)
		return (4);
	map->full = line[idx];
	line[idx--] = 0;
	map->obstacle = line[idx];
	line[idx--] = 0;
	map->empty = line[idx];
	line[idx--] = 0;
	map->height = ft_atoi(line);
	if (map->full == map->obstacle || map->full == map->empty
		|| map->empty == map->obstacle || map->height == -1)
		return (5);
	if (map->height <= 0)
		return (6);
	map->grid = malloc(sizeof(char *) * map->height);
	if (map->grid == NULL)
		return (3);
	*current_line = 0;
	return (0);
}

int	ft_setup_line(t_map *map, char *line, int *current_line)
{
	int	len;

	len = ft_strlen(line);
	if (map->width == -1)
	{
		if (len == 0)
			return (7);
		map->width = len;
	}
	if (len != map->width)
		return (9);
	map->grid[*current_line] = malloc(sizeof(char) * map->width);
	if (map->grid[*current_line] == NULL)
		return (3);
	if (ft_disgusting_free(map, line, len, current_line))
		return (8);
	*current_line += 1;
	return (0);
}

void	ft_reset_line(char *line, int *index, int *err)
{
	*index = 0;
	while (*index < LINE_LIMIT)
		line[(*index)++] = 0;
	*index = 0;
	*err = 0;
}
