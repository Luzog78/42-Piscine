/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:09 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/24 12:05:10 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*duplicated;

	i = 0;
	while (src[i])
		i++;
	duplicated = malloc(sizeof(char) * (i + 1));
	if (duplicated != NULL)
	{
		i = 0;
		while (src[i])
		{
			duplicated[i] = src[i];
			i++;
		}
		duplicated[i] = '\0';
	}
	return (duplicated);
}
