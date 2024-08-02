/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:07:13 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/26 10:08:46 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new;
	int	i;

	new = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		new[i] = f(tab[i]);
		i++;
	}
	return (new);
}
