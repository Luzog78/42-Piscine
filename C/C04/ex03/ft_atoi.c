/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:54:53 by ysabik            #+#    #+#             */
/*   Updated: 2023/07/17 07:02:07 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
int	ft_is_whitespace(char c);

int	ft_atoi(char *str)
{
	int		sum;
	int		negative_multiplier;

	while (ft_is_whitespace(*str))
		str++;
	negative_multiplier = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative_multiplier *= -1;
		str++;
	}
	sum = 0;
	while ('0' <= *str && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	return (sum * negative_multiplier);
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
