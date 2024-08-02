/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:20:33 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/18 08:38:55 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);
int		ft_find_exact(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	if (!(*to_find))
		return (str);
	while (*str)
	{
		if (ft_find_exact(str, to_find))
			return (str);
		str++;
	}
	return (0);
}

int	ft_find_exact(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] && to_find[i])
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	if (to_find[i])
		return (0);
	return (1);
}
