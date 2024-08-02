/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:56 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/26 10:21:49 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tab_len(char **tab);
void	ft_swap(char **a, char **b);
int		ft_strcmp(char *s1, char *s2);

void	ft_sort_string_tab(char **tab)
{
	int	len;
	int	i;

	len = ft_tab_len(tab);
	i = 0;
	if (len < 2)
		return ;
	while (i < len - 1)
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

int	ft_tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
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
