/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:36:19 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/13 15:36:21 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
int		ft_is_alphanumeric(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	space_before;

	i = 0;
	space_before = 1;
	while (str[i])
	{
		if (ft_is_alphanumeric(str[i]))
		{
			if (space_before)
			{
				if ('a' <= str[i] && str[i] <= 'z')
					str[i] -= 32;
				space_before = 0;
			}
			else
				if ('A' <= str[i] && str[i] <= 'Z')
					str[i] += 32;
		}
		else
			space_before = 1;
		i++;
	}
	return (str);
}

int	ft_is_alphanumeric(char c)
{
	return (!((c < '0' || c > '9')
			&& (c < 'A' || c > 'Z')
			&& (c < 'a' || c > 'z')));
}
