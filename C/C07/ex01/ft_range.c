/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:11 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/24 12:05:12 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*tab;

	if (min >= max)
		return (NULL);
	len = max - min;
	tab = malloc(sizeof(int) * len);
	if (tab != NULL)
	{
		i = 0;
		while (i < len)
		{
			tab[i] = i + min;
			i++;
		}
	}
	return (tab);
}
