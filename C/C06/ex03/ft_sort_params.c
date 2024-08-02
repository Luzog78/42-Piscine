/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:37:05 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/18 13:37:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(char **tab, int size);
void	ft_swap(char **a, char **b);
int		ft_strcmp(char *s1, char *s2);

int	main(int ac, char **av)
{
	int	i;

	ac--;
	av++;
	ft_sort_int_tab(av, ac);
	i = -1;
	while (++i < ac)
	{
		while (*(av[i]))
			write(1, av[i]++, 1);
		write(1, "\n", 1);
	}
	return (0);
}

void	ft_sort_int_tab(char **tab, int size)
{
	int	i;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i])
		return (s1[i]);
	if (s2[i])
		return (-s2[i]);
	return (0);
}
