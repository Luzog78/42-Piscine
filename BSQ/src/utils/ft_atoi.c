/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:54:53 by ysabik            #+#    #+#             */
/*   Updated: 2023/08/02 19:38:49 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
int	ft_is_whitespace(char c);

int	ft_atoi(char *str)
{
	int		sum;

	sum = 0;
	while ('0' <= *str && *str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	if (*str)
		return (-1);
	return (sum);
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
