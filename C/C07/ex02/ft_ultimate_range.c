/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:14 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/24 12:05:15 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;
	int	*tab;

	if (min >= max)
		return (0);
	len = max - min;
	tab = malloc(sizeof(int) * len);
	if (tab == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		tab[i] = i + min;
		i++;
	}
	*range = tab;
	return (i);
}
