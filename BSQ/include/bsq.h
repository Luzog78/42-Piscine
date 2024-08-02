/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:46:08 by ysabik            #+#    #+#             */
/*   Updated: 2023/08/02 20:08:57 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_solution
{
	t_pos				pos;
	int					size;
}	t_solution;

typedef struct s_map
{
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
	int		**dist;
}	t_map;

void	ft_init_pos(t_pos *pos, int x, int y);

void	ft_init_sol(t_solution *sol, int x, int y, int size);

void	ft_init_map(t_map *map);
int		ft_create_dist(t_map *map);
int		ft_free_those_before(t_map *map, int current_line,
			int free_dist, int err);
void	ft_print_map(t_map map);
void	ft_fill(t_map *map, t_solution sol);

int		ft_parse_map(t_map *map, char *file);

int		ft_solution(t_map *map, t_solution *solution);

int		ft_disgusting_free(t_map *map, char *line, int len, int *current_line);

#endif
