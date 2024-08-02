/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:46:25 by ysabik            #+#    #+#             */
/*   Updated: 2023/08/01 15:44:04 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	ft_init_sol(t_solution *sol, int x, int y, int size)
{
	sol->pos.x = x;
	sol->pos.y = y;
	sol->size = size;
}
