/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:44:15 by ysabik            #+#    #+#             */
/*   Updated: 2023/08/02 20:32:56 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "include/bsq.h"
#include "include/utils.h"
#include "include/err.h"

void	ft_execute(char *file);

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		ft_execute(0);
	else
	{
		while (i < ac)
		{
			ft_execute(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}

void	ft_execute(char *file)
{
	t_map		map;
	t_solution	sol;
	int			err;

	ft_init_map(&map);
	err = ft_parse_map(&map, file);
	if (err)
		ft_puterr(ERR_MAP);
	if (err)
		return ;
	ft_init_sol(&sol, 0, 0, 0);
	if (ft_solution(&map, &sol))
		ft_fill(&map, sol);
	ft_print_map(map);
	ft_free_those_before(&map, map.height, 1, 0);
	return ;
}
