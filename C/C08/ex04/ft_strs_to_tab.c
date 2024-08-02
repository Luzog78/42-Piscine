/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:39:31 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/25 13:56:57 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str);
char	*ft_strdup(char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	t_stock_str	current;
	int			i;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		current.size = ft_strlen(av[i]);
		current.str = av[i];
		current.copy = ft_strdup(av[i]);
		tab[i] = current;
		i++;
	}
	current.size = 0;
	current.str = 0;
	current.copy = 0;
	tab[i] = current;
	return (tab);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
